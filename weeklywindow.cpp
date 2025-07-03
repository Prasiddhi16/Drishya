#include "weeklywindow.h"
#include "ui_weeklywindow.h"

weeklyWindow::weeklyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::weeklyWindow)
{
    ui->setupUi(this);
    QBarSeries *series = new QBarSeries();
    QBarSet *week1 = new QBarSet("Week 1");
    week1->append(30);
    week1->setColor(Qt::red);  // Red color for Week 1

    QBarSet *week2 = new QBarSet("Week 2");
    week2->append(90);
    week2->setColor(Qt::blue);  // Blue color for Week 2

    // Add bar sets to the series
    series->append(week1);
    series->append(week2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Weekly Review");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList week;
    week<<"";

    QBarCategoryAxis*axisX=new QBarCategoryAxis();
    axisX->append(week);
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

weeklyWindow::~weeklyWindow()
{
    delete ui;
}
