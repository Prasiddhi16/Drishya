#include "reviewwindow.h"
#include "ui_reviewwindow.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>

reviewWindow::reviewWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reviewWindow)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->append("Food", 10);
    series->append("Shopping", 10);
    series->append("Housing", 30);
    series->append("Entertainment", 10);
    series->append("Transport", 10);
    series->append("Electronics", 8);
    series->append("Investment", 20);
    series->append("Others", 2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expense Review");
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView); // Shows chart in main window
}

reviewWindow::~reviewWindow()
{
    delete ui;
}
