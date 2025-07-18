#include "expert.h"
#include "ui_expert.h"
#include <QtCharts>
#include <QSqlQuery>
#include <QSqlError>
#include <cmath>
#include <numeric>   /
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>

expert::expert(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::expert)
{
    ui->setupUi(this);
    loadExpertReviewPage();
    connect(ui->btnRefresh, &QPushButton::clicked, this, &expert::loadExpertReviewPage);
}

expert::~expert() { delete ui; }

void expert::loadExpertReviewPage()
{
    qDebug() << "------------------------------------------";
    qDebug() << "Entering expert::loadExpertReviewPage()";

    QVector<double> incomeValues;
    QVector<double> expenseValues;

    QSqlDatabase db = QSqlDatabase::database("MainConnection");
    if (!db.isValid() || !db.isOpen()) {
        qDebug() << "ERROR: Database connection is not valid or not open in expert::loadExpertReviewPage()!";
        qDebug() << "Error:" << db.lastError().text();
        ui->InsightBox->setText("Database connection error. Cannot load expert review.");

        QLayoutItem *child;
        while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        return;
    }

    QSqlQuery query(db);
    QString recordsQueryString = "SELECT income_amount, expenses_amount FROM records"; // Fetch both
    qDebug() << "Executing query:" << recordsQueryString;

    if (query.exec(recordsQueryString)) {
        qDebug() << "Query for income and expenses executed successfully.";
        QSqlRecord record = query.record();
        int incomeIndex = record.indexOf("income_amount");
        int expensesIndex = record.indexOf("expenses_amount");

        if (incomeIndex == -1 || expensesIndex == -1) {
            qDebug() << "ERROR: 'income_amount' or 'expenses_amount' column not found in 'records' table!";
            QStringList fieldNames;
            for (int i = 0; i < record.count(); ++i) {
                fieldNames << record.fieldName(i);
            }
            qDebug() << "Available fields in 'records' table:" << fieldNames;
            ui->InsightBox->setText("Error: Required columns missing in records table.");

            QLayoutItem *child;
            while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }
            return;
        }

        while (query.next()) {
            incomeValues.append(query.value(incomeIndex).toDouble());
            expenseValues.append(query.value(expensesIndex).toDouble());
        }

        if (incomeValues.isEmpty() && expenseValues.isEmpty()) {
            qDebug() << "No income or expense records found.";
            ui->InsightBox->setText("No financial data available for analysis.");

            QLayoutItem *child;
            while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }
            return;
        }

        QString incomeInsight = "No income data.";
        if (!incomeValues.isEmpty()) {
            double meanIncome = std::accumulate(incomeValues.begin(), incomeValues.end(), 0.0) / incomeValues.size();
            double varianceIncome = 0;
            for (double val : incomeValues) varianceIncome += (val - meanIncome) * (val - meanIncome);
            double stddevIncome = std::sqrt(varianceIncome / incomeValues.size());

            incomeInsight = (stddevIncome > 3000)
                                ? "🔍 Income is unstable. Consider diversifying sources."
                                : "✅ Income is stable. Keep up the good work!";
        }

        // --- Expense Analysis and Insight ---
        QString expenseInsight = "No expense data.";
        if (!expenseValues.isEmpty()) {
            double meanExpense = std::accumulate(expenseValues.begin(), expenseValues.end(), 0.0) / expenseValues.size();
            double varianceExpense = 0;
            for (double val : expenseValues) varianceExpense += (val - meanExpense) * (val - meanExpense);
            double stddevExpense = std::sqrt(varianceExpense / expenseValues.size());

            expenseInsight = (stddevExpense > 2000)
                                 ? "⚠️ Expenses are fluctuating. Review spending habits."
                                 : "👍 Expenses are stable. Good control!";
        }

        ui->InsightBox->setText("Income Insight: " + incomeInsight + "\n\n" + "Expense Insight: " + expenseInsight);



        QLineSeries *incomeSeries = new QLineSeries();
        incomeSeries->setName("Income");
        for (int i = 0; i < incomeValues.size(); ++i)
            incomeSeries->append(i + 1, incomeValues[i]);

        QLineSeries *expenseSeries = new QLineSeries();
        expenseSeries->setName("Expenses");
        for (int i = 0; i < expenseValues.size(); ++i)
            expenseSeries->append(i + 1, expenseValues[i]);

        QChart *chart = new QChart();
        chart->addSeries(incomeSeries);
        chart->addSeries(expenseSeries);
        chart->setTitle("Financial Trends (Income vs. Expenses)");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Configure X and Y axes
        QValueAxis *axisX = new QValueAxis;
        axisX->setTitleText("Record");
        QValueAxis *axisY = new QValueAxis;
        axisY->setTitleText("Amount");
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
        incomeSeries->attachAxis(axisX);
        incomeSeries->attachAxis(axisY);
        expenseSeries->attachAxis(axisX);
        expenseSeries->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Clear existing chart from layout before adding new one
        QLayoutItem *child;
        while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }

        ui->chartLayout->addWidget(chartView);

    } else {
        qDebug() << "ERROR: Query for income/expenses FAILED to execute!";
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Driver Error:" << query.lastError().driverText();
        qDebug() << "Database Error:" << query.lastError().databaseText();
        ui->InsightBox->setText("Error retrieving financial data. Check database schema and connection.");
        // Clear existing chart if any
        QLayoutItem *child;
        while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }
    qDebug() << "Exiting expert::loadExpertReviewPage()";
}

