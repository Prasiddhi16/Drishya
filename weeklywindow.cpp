#include "weeklywindow.h"
#include "ui_weeklywindow.h"

#include <QtCharts>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDebug>
#include <QCloseEvent>
#include <QMap>

weeklyWindow::weeklyWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::weeklyWindow),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);

    QString connectionName = "qt_sql_weekly_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qDebug() << "Resolved DB Path in weeklyWindow:" << dbPath;

    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    QString currentMonth = QDate::currentDate().toString("yyyy-MM");

    QString sql = R"(SELECT timestamp,
                            SUM(expense_amount) AS total
                     FROM records
                     WHERE expense_amount > 0
                       AND user_id = :uid
                       AND strftime('%Y-%m', timestamp) = :month
                     GROUP BY strftime('%Y-%m-%d', timestamp)
                     ORDER BY timestamp)";

    query.prepare(sql);
    query.bindValue(":uid", currentUserId);
    query.bindValue(":month", currentMonth);

    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QMap<int, double> weeklyTotals;
    QDate monthStart = QDate::fromString(currentMonth + "-01", "yyyy-MM-dd");

    while (query.next()) {
        QString dateStr = query.value(0).toString(); // format: yyyy-MM-dd HH:mm:ss
        QDate recordDate = QDate::fromString(dateStr.left(10), "yyyy-MM-dd");
        int dayOffset = monthStart.daysTo(recordDate);
        int weekOfMonth = (dayOffset / 7) + 1;

        double amount = query.value(1).toDouble();
        weeklyTotals[weekOfMonth] += amount;
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *barSet = new QBarSet("This Month");
    QStringList weekLabels;
    qreal maxExpense = 0.0;

    if (!weeklyTotals.isEmpty()) {
        for (int week = 1; week <= weeklyTotals.lastKey(); ++week) {
            double total = weeklyTotals.value(week, 0.0);
            maxExpense = qMax(maxExpense, total);

            QString label = QString("Week %1").arg(week);
            weekLabels << label;
            barSet->append(total);
        }

        barSet->setColor(Qt::blue);
        series->append(barSet);
    }

    QChart *chart = new QChart();
    chart->setTitle(QString("Weekly Expense – %1").arg(QDate::currentDate().toString("MMMM yyyy")));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    if (!weeklyTotals.isEmpty()) {
        chart->addSeries(series);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(weekLabels);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setLabelFormat("Rs. %d");
        axisY->setTitleText("Total Expense");
        axisY->setRange(0, maxExpense + 10000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    } else {
        chart->setTitle("No data available for this month.");
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    this->showMaximized();
}

weeklyWindow::~weeklyWindow()
{
    delete ui;
}

void weeklyWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
