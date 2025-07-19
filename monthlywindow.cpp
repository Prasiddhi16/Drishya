#include "monthlywindow.h"
#include "ui_monthlywindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtCharts>
#include <QDate>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QDebug>

monthlyWindow::monthlyWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::monthlyWindow)
    , currentUserEmail(userEmail),
    currentUserId(userId)

{
    ui->setupUi(this);

    QString connectionName = "qt_sql_monthly_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/centralized.db");


    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        return;
    }


    QSqlQuery query(db);
    QString sql = R"(
    SELECT strftime('%m', timestamp) AS month, SUM(expense_amount)
    FROM records
    WHERE expense_amount > 0 AND user_id = :uid
    GROUP BY month
    ORDER BY month
)";
    query.prepare(sql);
    query.bindValue(":uid", currentUserId);
    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QBarSeries *series = new QBarSeries();
    QStringList monthLabels;
    QList<QColor> barColors = {
        Qt::red, Qt::blue, Qt::green, Qt::magenta, Qt::cyan,
        Qt::darkYellow, Qt::darkRed, Qt::darkBlue,
        Qt::darkGreen, Qt::darkMagenta, Qt::darkCyan, Qt::gray
    };

    int i = 0;
    while (query.next()) {
        QString monthNum = query.value(0).toString();  // e.g. '01'
        int value = query.value(1).toInt();
        QStringList monthNames = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        QString shortMonth = monthNames.value(monthNum.toInt() - 1);
        monthLabels << shortMonth;

        QBarSet *bar = new QBarSet(shortMonth);
        for (int j = 0; j <= i; ++j) {
            bar->append(j == i ? value : 0);
        }

        bar->setColor(barColors[i % barColors.size()]);
        series->append(bar);
        ++i;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Monthly Expense Review");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(monthLabels);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,500000);  // You can adjust this or compute max dynamically
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    this->showMaximized();
}

monthlyWindow::~monthlyWindow()
{
    delete ui;
}

void monthlyWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
