#include "graph.h"
#include "ui_graph.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QDebug> // Include for qDebug

// Modified constructor to accept actual data
graph::graph(QWidget *parent, qreal income, qreal expenses, qreal savingAmount)
    : QMainWindow(parent)
    , ui(new Ui::graph)
{
    qDebug() << "Graph: Entering constructor.";
    ui->setupUi(this);
    this->resize(800, 600); // ADDED: Explicitly set a default size for the graph window
    qDebug() << "Graph: setupUi completed and window resized.";

    qDebug() << "Graph: Constructor received data:";
    qDebug() << "Income:" << income;
    qDebug() << "Expenses:" << expenses;
    qDebug() << "Saving:" << savingAmount;

    // Use the actual data passed to the constructor
    qreal totalIncome = income;
    qreal saving = savingAmount;
    qreal expense = expenses; // Use the passed expenses directly

    // Handle cases where totalIncome might be zero or negative to avoid division by zero or nonsensical percentages
    if (totalIncome <= 0) {
        qDebug() << "Graph: Warning: Total income is zero or negative. Pie chart might not be meaningful.";
        // You might want to display a message or a blank chart instead
        totalIncome = 1; // Prevent division by zero for percentage calculation if needed, or set slices to 0
        saving = 0;
        expense = 0;
    }

    // Pie chart setup
    QPieSeries *series = new QPieSeries();

    // Only add slices if their values are positive to avoid issues with 0 or negative values
    if (saving > 0) {
        series->append("Saving", saving);
        qDebug() << "Graph: Added Saving slice:" << saving;
    } else {
        qDebug() << "Graph: Saving amount is zero or negative, not adding to pie chart.";
    }

    if (expense > 0) {
        series->append("Expense", expense);
        qDebug() << "Graph: Added Expense slice:" << expense;
    } else {
        qDebug() << "Graph: Expense amount is zero or negative, not adding to pie chart.";
    }

    // If no slices are added, add a "No Data" slice or handle appropriately
    if (series->slices().isEmpty()) {
        qDebug() << "Graph: No positive data slices, adding 'No Data' slice.";
        series->append("No Data", 1); // Add a small slice to show something
        QPieSlice *noDataSlice = series->slices().at(0);
        noDataSlice->setLabelVisible(true);
        noDataSlice->setBrush(Qt::lightGray);
        noDataSlice->setLabel("No Data");
    } else {
        // Optional: highlight saving slice (only if saving slice exists)
        // Find the saving slice by its label or value if it's not always the first
        for (QPieSlice *slice : series->slices()) {
            if (slice->label() == "Saving") {
                slice->setExploded(true);
                slice->setLabelVisible(true);
                slice->setPen(QPen(Qt::darkGreen, 2));
                slice->setBrush(Qt::green);
                qDebug() << "Graph: Highlighted Saving slice.";
                break;
            }
        }
    }


    // Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Income Breakdown"); // Title remains "Income Breakdown" for this pie chart
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Enable smooth animation
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Chart View
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set chart to central widget
    setCentralWidget(chartView);
    qDebug() << "Graph: Chart set as central widget.";
    qDebug() << "Graph: Exiting constructor.";
}

graph::~graph()
{
    qDebug() << "Graph: Entering destructor.";
    delete ui;
    qDebug() << "Graph: Destructor completed.";
}
