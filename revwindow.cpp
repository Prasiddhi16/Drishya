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

revWindow::revWindow(const QString &userEmail, int userId,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::revWindow)
    , currentUserEmail(userEmail)
    , currentUserId(userId)
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
        qDebug() << "❌ DB Open Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT expense_category, SUM(expense_amount) FROM records WHERE user_id = :uid GROUP BY expense_category");
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

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    this->showMaximized();
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
