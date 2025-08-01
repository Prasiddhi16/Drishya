#include "revwindow.h"
#include "ui_revwindow.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPainter>
#include <QDebug>
#include <QCloseEvent>
#include <QCoreApplication>
#include <QDir>
#include <QTimer>

revWindow::revWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::revWindow)
    , currentUserEmail(userEmail)
    , currentUserId(userId)
    , refreshTimer(new QTimer(this))
    , chartView(new QChartView(this))
{
    ui->setupUi(this);

    QString connectionName = "qt_sql_monthly_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qDebug() << "Resolved DB Path in monthlyWindow:" << dbPath;

    if (!db.open()) {
        qDebug() << " DB Open Error:" << db.lastError().text();
        return;
    }

    setCentralWidget(chartView);
    this->showMaximized();


    refreshChart();


    connect(refreshTimer, &QTimer::timeout, this, &revWindow::refreshChart);
    refreshTimer->start(15000);
}

void revWindow::refreshChart()
{
    QSqlDatabase db = QSqlDatabase::database("qt_sql_monthly_connection");
    QSqlQuery query(db);

    query.prepare(R"(
        SELECT expense_category, SUM(expense_amount)
        FROM records
        WHERE user_id = :uid
          AND expense_amount > 0
          AND strftime('%W', timestamp) = strftime('%W', 'now')
          AND strftime('%Y', timestamp) = strftime('%Y', 'now')
        GROUP BY expense_category
    )");

    query.bindValue(":uid", currentUserId);

    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QPieSeries *series = new QPieSeries(this);
    series->setHoleSize(0.25);
    bool hasData = false;

    while (query.next()) {
        QString category = query.value(0).toString();
        double total = query.value(1).toDouble();
        series->append(category, total);
        hasData = true;
    }

    if (!hasData) {
        qDebug() << "No data found for pie chart.";
        return;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expense Distribution by Category");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    for (auto slice : series->slices()) {
        QString category = slice->label();
        qreal percentage = slice->percentage() * 100.0;
        slice->setLabel(QString("%1: %2%").arg(category).arg(percentage, 0, 'f', 1));
        slice->setLabelVisible(true);
    }

}

revWindow::~revWindow()
{
    delete ui;
}

void revWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
