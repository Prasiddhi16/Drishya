#include "compare.h"
#include "ui_compare.h"
#include <QtCharts>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <algorithm>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

// Constructor: Initializes the UI and stores the user ID
compare::compare(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::compare), m_userId(userId) // Initialize m_userId here
{
    ui->setupUi(this);
    setupChart(); // Call to set up the chart
    this ->showMaximized();
}

// Destructor: Cleans up the UI
compare::~compare() {
    delete ui;
}

// Function to set up and populate the chart with financial data
void compare::setupChart()
{
    qDebug() << "Entering setupChart() for user ID:" << m_userId;

    // Ensure a clean database connection. If a connection with this name already exists, remove it.
    const QString connectionName = "qt_sql_compare_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
        qDebug() << "Removed existing database connection:" << connectionName;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);

    // Construct the database path relative to the application's executable directory.
    // It assumes 'centralized.db' is one level up from the executable directory.
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString dbPath = QDir(appDirPath).absoluteFilePath("../centralized.db");

    qDebug() << "Attempting to open DB at:" << dbPath;
    qDebug() << "Does DB file exist at path?" << QFile::exists(dbPath);

    db.setDatabaseName(dbPath);

    // Try to open the database connection
    if (!db.open()) {
        qDebug() << "Failed to open database --" << db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Cannot access financial data. Please ensure 'centralized.db' is in the correct directory relative to the application.");
        return; // Exit if database cannot be opened
    }
    qDebug() << "Database opened successfully.";

    double totalIncome = 0.0;
    double totalExpenses = 0.0;
    // double actualSavings = 0.0; // This variable will now be calculated, not directly from DB

    // --- Retrieve Total Income and Expenses from 'records' table ---
    {
        QSqlQuery query(db);
        // Prepare SQL query to sum income_amount and expense_amount for the current user
        query.prepare("SELECT SUM(income_amount), SUM(expense_amount) FROM records WHERE user_id = :uid"); // Changed to SUM directly
        query.bindValue(":uid", m_userId); // Bind the user ID

        if (!query.exec()) {
            qDebug() << "Income/expense query failed:" << query.lastError().text();
            QMessageBox::critical(this, "Query Error", "Failed to retrieve income/expense data from 'records' table.");
            db.close(); // Close database connection on error
            return;
        }
        // No loop needed if using SUM()
        if (query.next()) {
            totalIncome   = query.value(0).toDouble();
            totalExpenses = query.value(1).toDouble();
        }
        qDebug() << "Calculated Total Income:" << totalIncome << ", Total Expenses:" << totalExpenses;
    }


    db.close();
    qDebug() << "Database connection closed.";

    // --- NEW: Calculate Actual Saving as totalIncome - totalExpenses (similar to graph.cpp) ---
    double actualSavings = totalIncome - totalExpenses;
    // Add a check for negative savings to display 0 on the chart if desired
    // if (actualSavings < 0) {
    //     actualSavings = 0; // Or handle negative savings appropriately for your display
    //     qDebug() << "Actual Savings calculated negative, setting to 0 for chart display.";
    // }
    qDebug() << "Calculated Actual Savings (Income - Expenses):" << actualSavings;


    // --- Calculate Ideal Saving (e.g., 30% of total income) ---
    double idealSaving = totalIncome * 0.3; // Define your ideal saving percentage here
    qDebug() << "Calculated Ideal Saving (30% of income):" << idealSaving;

    // --- Create Bar Sets for the Chart ---
    QBarSet *incomeSet        = new QBarSet("Income");
    QBarSet *expenseSet       = new QBarSet("Expenses");
    QBarSet *actualSavingSet  = new QBarSet("Actual Saving"); // This will now reflect income - expenses
    QBarSet *idealSavingSet   = new QBarSet("Ideal Saving");

    // Append the calculated values to their respective bar sets
    *incomeSet        << totalIncome;
    *expenseSet       << totalExpenses;
    *actualSavingSet  << actualSavings; // NOW uses the calculated actualSavings
    *idealSavingSet   << idealSaving;   // Use the calculated ideal saving

    // Set colors for each bar set for better visual distinction
    incomeSet->setColor(QColor("#3498DB"));      // Blue
    expenseSet->setColor(QColor("#E74C3C"));     // Red
    actualSavingSet->setColor(QColor("#2ECC71")); // Green
    idealSavingSet->setColor(QColor("#F1C40F")); // Yellow

    // --- Create Bar Series and Add Bar Sets ---
    QBarSeries *series = new QBarSeries();
    series->append(incomeSet);
    series->append(expenseSet);
    series->append(actualSavingSet);
    series->append(idealSavingSet);

    // --- Create Chart and Add Series ---
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Compare: Financial Overview"); // Updated title
    chart->setAnimationOptions(QChart::SeriesAnimations); // Enable animation for better user experience

    // --- Configure X-Axis (Categories) ---
    QStringList categories;
    categories << "Total"; // A single category for all bars, showing totals
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom); // Add X-axis to the bottom of the chart
    series->attachAxis(axisX); // Attach the series to the X-axis

    // --- Configure Y-Axis (Values) ---
    QValueAxis *axisY = new QValueAxis();
    // Determine the maximum value among all data points for appropriate Y-axis scaling
    double maxVal = std::max({totalIncome, totalExpenses, actualSavings, idealSaving});
    // Set the Y-axis range from 0 to maxVal with 15% padding for visual clarity
    axisY->setRange(0, maxVal * 1.15);
    axisY->setLabelFormat("%.1f"); // Format Y-axis labels to one decimal place
    chart->addAxis(axisY, Qt::AlignLeft); // Add Y-axis to the left of the chart
    series->attachAxis(axisY); // Attach the series to the Y-axis

    // --- Configure Legend ---
    chart->legend()->setVisible(true); // Make the legend visible
    chart->legend()->setAlignment(Qt::AlignBottom); // Position the legend at the bottom

    // --- Set the Chart to QChartView Widget ---
    ui->chartWidget->setChart(chart);
    ui->chartWidget->setRenderHint(QPainter::Antialiasing); // Enable anti-aliasing for smoother graphics

    qDebug() << "Chart display setup complete.";
}
void compare::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
