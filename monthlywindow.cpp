#include "monthlywindow.h"
#include "ui_monthlywindow.h"

monthlyWindow::monthlyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::monthlyWindow)
{
    ui->setupUi(this);

    QBarSeries *series = new QBarSeries();
    QBarSet *month1 = new QBarSet("Month 1");
    month1->append(30);
    month1->setColor(Qt::red);  // Red color for Week 1

    QBarSet *month2 = new QBarSet("Month 2");
    month2->append(90);
    month2->setColor(Qt::blue);  // Blue color for Week 2

    // Add bar sets to the series
    series->append(month1);
    series->append(month2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Weekly Review");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList month;
    month<<"";

    QBarCategoryAxis*axisX=new QBarCategoryAxis();
    axisX->append(month);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis*axisY=new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView ->setVisible(true);
    setCentralWidget(chartView);


}


monthlyWindow::~monthlyWindow()
{
    delete ui;
}
