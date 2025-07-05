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

revWindow::revWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::revWindow)
{
    ui->setupUi(this);


    QString connectionName = "qt_sql_budget_connection";
    QSqlDatabase db;

    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/MYFINANCERECORD/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/FINANCERECORD.db");

        if (!db.open()) {
            qDebug() << " DB Connection Error:" << db.lastError().text();
            return;
        }
    }


    QSqlQuery query(db);
    if (!query.exec("SELECT expense_category, SUM(amount) FROM readable_expenses GROUP BY expense_category")) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QPieSeries *series = new QPieSeries(this); // set parent for memory safety
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
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
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
