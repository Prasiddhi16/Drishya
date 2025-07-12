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

weeklyWindow::weeklyWindow(const QString &userEmail, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::weeklyWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);

    QString connectionName = "qt_sql_weekly_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QString dbBaseName = currentUserEmail.section('@', 0, 0);
    QString dbPath = QCoreApplication::applicationDirPath() + "/users/" + dbBaseName + ".db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    QString sql = R"(SELECT strftime('%W', timestamp) AS week_num, SUM(expense_amount)
                    FROM records
                    WHERE expense_amount > 0
                    GROUP BY week_num ORDER BY week_num)";

    if (!query.exec(sql)) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    QBarSeries *series = new QBarSeries();
    QList<QColor> barColors = { Qt::red, Qt::blue, Qt::green, Qt::magenta, Qt::darkCyan };
    QStringList weekLabels;
    int index = 0;

    while (query.next()) {
        QString weekNum = query.value(0).toString(); // e.g. "23"
        double total = query.value(1).toDouble();
        QString label = QString("Week %1").arg(weekNum);

        weekLabels << label;
        QBarSet *bar = new QBarSet(label);

        for (int i = 0; i <= index; ++i)
            bar->append(i == index ? total : 0);

        bar->setColor(barColors[index % barColors.size()]);
        series->append(bar);
        ++index;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Weekly Expense Review");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(weekLabels);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100); // You can adjust this later
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
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
