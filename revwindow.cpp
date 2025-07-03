#include "revwindow.h"
#include "ui_revwindow.h"

revWindow::revWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::revWindow)
{
    ui->setupUi(this);



    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25);
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
    chartView ->setVisible(true);
    setCentralWidget(chartView);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

revWindow::~revWindow()
{
    delete ui;
}
