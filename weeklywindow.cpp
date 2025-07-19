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
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/centralized.db");

    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    QString sql = R"(SELECT strftime('%Y-%m', timestamp) AS month_id,
                            strftime('%W', timestamp) AS week_id,
                            SUM(expense_amount)
                     FROM records
                     WHERE expense_amount > 0 AND user_id = :uid
                     GROUP BY month_id, week_id
                     ORDER BY month_id, week_id)";

    query.prepare(sql);
    query.bindValue(":uid", currentUserId);

    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QBarSeries *series = new QBarSeries();
    QList<QColor> barColors = { Qt::red, Qt::blue, Qt::green, Qt::magenta, Qt::darkCyan, Qt::darkYellow };
    QMap<QString, int> monthWeekCounter;
    QStringList weekLabels;
    int displayIndex = 0;

    while (query.next()) {
        QString month = query.value(0).toString();
        QString weekRaw = query.value(1).toString();
        double total = query.value(2).toDouble();

        if (!monthWeekCounter.contains(month)) {
            monthWeekCounter[month] = 1;
        } else {
            monthWeekCounter[month] += 1;
        }

        int weekNumDisplay = monthWeekCounter[month];
        QString label = QString("%1 - Week %2").arg(month).arg(weekNumDisplay);
        weekLabels << label;

        QBarSet *bar = new QBarSet(label);
        for (int i = 0; i <= displayIndex; ++i)
            bar->append(i == displayIndex ? total : 0);

        bar->setColor(barColors[displayIndex % barColors.size()]);
        series->append(bar);
        ++displayIndex;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Weekly Expense Review (Grouped by Month)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(weekLabels);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 50000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

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
