#include "graph.h"
#include "ui_graph.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QCoreApplication>

graph::graph(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::graph)
{
    qDebug() << "Graph: Entering constructor.";
    ui->setupUi(this);
    this->resize(800, 600);
    qDebug() << "Graph: UI setup complete and window resized.";

    // 🔌 Connect to the database
    QString connectionName = "qt_sql_graph_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qreal totalIncome = 0.0;
    qreal totalExpense = 0.0;
    qreal saving = 0.0;

    if (!db.open()) {
        qDebug() << "Graph: Failed to open database —" << db.lastError().text();
    } else {
        qDebug() << "Graph: Connected to database at:" << dbPath;

        // 📊 Query to sum income and expense
        QSqlQuery query(db);
        query.prepare("SELECT SUM(income_amount), SUM(expense_amount) FROM records WHERE user_id= :uid");
        query.bindValue(":uid", userId);


        if (query.exec() && query.next()) {
            totalIncome = query.value(0).toDouble();
            totalExpense = query.value(1).toDouble();
            saving = totalIncome - totalExpense;

            qDebug() << "Graph: Aggregated data — Income:" << totalIncome
                     << "Expense:" << totalExpense << "Saving:" << saving;
        } else {
            qDebug() << "Graph: Query failed —" << query.lastError().text();
        }
    }

    // 🚫 Prevent charting issues with zero income
    if (totalIncome <= 0) {
        totalIncome = 1;
        totalExpense = 0;
        saving = 0;
        qDebug() << "Graph: Adjusted invalid income to avoid empty chart.";
    }

    // 🥧 Create pie chart
    QPieSeries *series = new QPieSeries();
    if (saving > 0) {
        series->append("Saving", saving);
        qDebug() << "Graph: Added saving slice:" << saving;
    }
    if (totalExpense > 0) {
        series->append("Expense", totalExpense);
        qDebug() << "Graph: Added expense slice:" << totalExpense;
    }

    if (series->slices().isEmpty()) {
        series->append("No Data", 1);
        QPieSlice *noDataSlice = series->slices().at(0);
        noDataSlice->setLabelVisible(true);
        noDataSlice->setBrush(Qt::lightGray);
        noDataSlice->setLabel("No Data");
        qDebug() << "Graph: No valid data — Added placeholder slice.";
    } else {
        for (QPieSlice *slice : series->slices()) {
            if (slice->label() == "Saving") {
                slice->setExploded(true);
                slice->setLabelVisible(true);
                slice->setPen(QPen(Qt::darkGreen, 2));
                slice->setBrush(Qt::green);
                qDebug() << "Graph: Highlighted saving slice.";
                break;
            }
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Income Breakdown");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);

    qDebug() << "Graph: Chart ready.";
    this->showMaximized();
}

graph::~graph()
{
    qDebug() << "Graph: Destructor called.";
    delete ui;
}
