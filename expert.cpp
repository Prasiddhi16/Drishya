#include "expert.h"
#include "ui_expert.h"
#include <QtCharts>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <cmath>
#include <numeric>

expert::expert(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::expert),
    m_userEmail(userEmail),
    m_userId(userId),
    m_userName(userEmail.section('@', 0, 0))  // Optional: Extract name from email
{
    ui->setupUi(this);
    connectToDatabase();
    loadExpertReviewPage();
    this->showMaximized();
}

expert::~expert() { delete ui; }

void expert::connectToDatabase()
{
    if (!QSqlDatabase::contains("MainConnection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MainConnection");
        db.setDatabaseName("centralized.db");
        if (!db.open()) {
            qDebug() << "❌ Database connection failed:" << db.lastError().text();
        } else {
            qDebug() << "✅ Database connected successfully.";
        }
    }
}

void expert::loadExpertReviewPage()
{
    qDebug() << "------------------------------------------";
    qDebug() << "Entering expert::loadExpertReviewPage()";

    QSqlDatabase db = QSqlDatabase::database("MainConnection");
    if (!db.isValid() || !db.isOpen()) {
        ui->InsightBox->setText("Database connection error. Cannot load expert review.");
        clearChartLayout();
        return;
    }

    QMap<int, double> incomeMap, expenseMap;
    QSqlQuery query(db);

    // Fetch Monthly Income
    query.prepare("SELECT strftime('%m', timestamp) AS month, SUM(income_amount) FROM records WHERE user_id = :uid GROUP BY month");
    query.bindValue(":uid", m_userId);
    if (query.exec()) {
        while (query.next()) {
            int month = query.value(0).toInt();
            double income = query.value(1).toDouble();
            incomeMap[month] = income;
        }
    } else {
        qDebug() << "Income query failed:" << query.lastError();
    }

    // Fetch Monthly Expenses
    query.prepare("SELECT strftime('%m', timestamp) AS month, SUM(expense_amount) FROM records WHERE user_id = :uid GROUP BY month");
    query.bindValue(":uid", m_userId);
    if (query.exec()) {
        while (query.next()) {
            int month = query.value(0).toInt();
            double expense = query.value(1).toDouble();
            expenseMap[month] = expense;
        }
    } else {
        qDebug() << "Expense query failed:" << query.lastError();
    }

    QVector<double> incomeValues, expenseValues, savingValues;

    QLineSeries *incomeSeries  = new QLineSeries(); incomeSeries->setName("Income");
    QLineSeries *expenseSeries = new QLineSeries(); expenseSeries->setName("Expenses");
    QLineSeries *savingSeries  = new QLineSeries(); savingSeries->setName("Savings");

    incomeSeries->setColor(QColor("#3498db"));   // Blue
    expenseSeries->setColor(QColor("#e74c3c"));  // Red
    savingSeries->setColor(QColor("#2ecc71"));   // Green

    double minVal = 0.0, maxVal = 0.0;

    for (int month = 1; month <= 12; ++month) {
        double income = incomeMap.value(month, 0.0);
        double expense = expenseMap.value(month, 0.0);
        double savings = income - expense;

        incomeValues.append(income);
        expenseValues.append(expense);
        savingValues.append(savings);

        // Optional: incomeSeries->append(month, income);
        expenseSeries->append(month, expense);
        savingSeries->append(month, savings);

        maxVal = std::max({maxVal, income, expense, savings});
        if (savings < minVal) minVal = savings;
    }

    // 📋 Generate Insights
    QString incomeInsight  = generateInsight(incomeValues, 3000, "Income");
    QString expenseInsight = generateInsight(expenseValues, 2000, "Expenses");
    QString savingInsight  = generateInsight(savingValues, 2500, "Savings");
    ui->InsightBox->setText(incomeInsight + "\n\n" + expenseInsight + "\n\n" + savingInsight);

    // 📊 Build Chart
    QChart *chart = new QChart();
    chart->addSeries(incomeSeries);
    chart->addSeries(expenseSeries);
    chart->addSeries(savingSeries);
    chart->setTitle("📈 Monthly Financial Trends");
    chart->setBackgroundBrush(QBrush(QColor("#ffffff")));
    chart->setTitleBrush(QBrush(Qt::black));
    chart->legend()->setLabelBrush(QBrush(Qt::black));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QCategoryAxis *axisX = new QCategoryAxis;
    axisX->setTitleText("Month");
    QStringList monthLabels = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int i = 1; i <= 12; ++i)
        axisX->append(monthLabels[i - 1], i);
    axisX->setRange(1, 12);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Amount (NPR)");
    axisY->setRange(minVal < 0 ? minVal - 500 : 0, maxVal + 1000);
    axisY->applyNiceNumbers();

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    incomeSeries->attachAxis(axisX);  incomeSeries->attachAxis(axisY);
    expenseSeries->attachAxis(axisX); expenseSeries->attachAxis(axisY);
    savingSeries->attachAxis(axisX);  savingSeries->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedHeight(300);
    chartView->setStyleSheet("background: transparent");

    clearChartLayout();
    ui->chartLayout->addWidget(chartView);

    qDebug() << "Exiting expert::loadExpertReviewPage()";
}

QString expert::generateInsight(const QVector<double> &values, double threshold, const QString &label)
{
    if (values.isEmpty())
    {return QString("No %1 data available.").arg(label);}
    if (std::all_of(values.begin(), values.end(), [](double v) { return v == 0.0; })) {
        return QString("ℹ️ No meaningful %1 data for the selected period.").arg(label);
    }

    double mean = std::accumulate(values.begin(), values.end(), 0.0) / values.size();
    double variance = 0;
    for (double val : values) variance += std::pow(val - mean, 2);
    double stddev = std::sqrt(variance / values.size());

    if (stddev > threshold) {
        return QString("⚠️ %1 is fluctuating. Consider strategic adjustments.").arg(label);
    } else {
        return QString("✅ %1 appears stable and well-managed.").arg(label);
    }
}

void expert::clearChartLayout()
{
    QLayoutItem *child;
    while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}
void expert::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
