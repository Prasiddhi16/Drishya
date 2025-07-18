#include "compare.h"
#include "ui_compare.h"
#include <QtCharts>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord> // Include QSqlRecord
#include <QMessageBox> // For user feedback

compare::compare(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::compare)
{
    ui->setupUi(this);
    setupChart();
}

compare::~compare() { delete ui; }

void compare::setupChart()
{
    qDebug() << "------------------------------------------";
    qDebug() << "Entering compare::setupChart()";

    QBarSet *incomeSet = new QBarSet("Income");
    QBarSet *expenseSet = new QBarSet("Expenses");
    QBarSet *savingSet = new QBarSet("Saving");

    QSqlDatabase db = QSqlDatabase::database("MainConnection");

    // --- Check Database Connection Status ---
    if (!db.isValid() || !db.isOpen()) {
        qDebug() << "ERROR: Database connection 'MainConnection' is not valid or not open in compare::setupChart()!";
        qDebug() << "Error: " << db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Cannot access financial data. Database connection is not active.");
        return; // Exit if the connection is not ready
    }

    double totalIncome = 0, totalExpenses = 0, saving = 0;

    // --- Query 1: Get total income and expenses from 'records' table ---
    QSqlQuery query(db);
    QString recordsQueryString = "SELECT income_amount, expenses_amount FROM records";
    query.prepare(recordsQueryString);
    qDebug() << "Debug Point 2: Executing query:" << recordsQueryString;

    if (query.exec()) { // Check if the query executed successfully
        qDebug() << "Debug Point 2: Query for 'records' table executed successfully.";
        QSqlRecord record = query.record(); // Get the record object to access field information
        int incomeIndex = record.indexOf("income_amount");
        int expensesIndex = record.indexOf("expenses_amount");

        if (incomeIndex == -1 || expensesIndex == -1) {
            qDebug() << "Debug Point 2: ERROR - 'income_amount' or 'expenses_amount' column not found in 'records' table!";
            QStringList fieldNames;
            for (int i = 0; i < record.count(); ++i) {
                fieldNames << record.fieldName(i);
            }
            qDebug() << "Available fields in 'records' table:" << fieldNames;
            QMessageBox::warning(this, "Data Error", "Required columns missing in 'records' table. Chart may be incomplete.");
        }

        while (query.next()) { // Iterate through results
            if (incomeIndex != -1) {
                totalIncome += query.value(incomeIndex).toDouble();
            }
            if (expensesIndex != -1) {
                totalExpenses += query.value(expensesIndex).toDouble();
            }
            qDebug() << "Debug Point 2.1: Fetched income record:" << query.value(incomeIndex).toDouble()
                     << ", expenses record:" << query.value(expensesIndex).toDouble();
        }
        // Check if any rows were processed.
        if (totalIncome == 0 && totalExpenses == 0 && query.isSelect()) {
            qDebug() << "Debug Point 2: Query for 'records' executed successfully, but returned 0 rows.";
        } else if (query.isSelect()) {
            qDebug() << "Debug Point 2: Query for 'records' executed successfully, and rows were processed.";
        }

    } else {
        qDebug() << "Debug Point 2.2: Query for 'records' table FAILED to execute!";
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Driver Error:" << query.lastError().driverText();
        qDebug() << "Database Error:" << query.lastError().databaseText();
        QMessageBox::critical(this, "Query Error", "Failed to retrieve income/expenses data. " + query.lastError().text());
    }

    // --- Query 2: Get saving from 'user' table ---
    QSqlQuery userQuery(db);
    QString userQueryString = "SELECT Saving FROM user WHERE uid = 1";
    qDebug() << "Debug Point 3: Executing user query:" << userQueryString;

    if (userQuery.exec(userQueryString)) {
        qDebug() << "Debug Point 3: User query executed successfully.";
        QSqlRecord userRecord = userQuery.record(); // Get the record object
        int savingIndex = userRecord.indexOf("Saving");
        if (savingIndex == -1) {
            qDebug() << "Debug Point 3: ERROR - 'Saving' column not found in 'user' table!";
            QStringList fieldNames;
            for (int i = 0; i < userRecord.count(); ++i) {
                fieldNames << userRecord.fieldName(i);
            }
            qDebug() << "Available fields in 'user' table:" << fieldNames;
            QMessageBox::warning(this, "Data Error", "Required 'Saving' column missing in 'user' table. Saving data may be incomplete.");
        }

        if (userQuery.next()) { // Check if there's a row to fetch
            if (savingIndex != -1) {
                saving = userQuery.value(savingIndex).toDouble();
                qDebug() << "Debug Point 3.1: Fetched saving:" << saving;
            } else {
                qDebug() << "Debug Point 3.1: Skipping saving value fetch due to missing column.";
            }
        } else {
            qDebug() << "Debug Point 3.2: User query executed successfully, but returned 0 rows (no user with uid=1 found or no 'Saving' data).";
        }
    } else {
        qDebug() << "Debug Point 3.3: User query FAILED to execute!";
        qDebug() << "SQL Error:" << userQuery.lastError().text();
        qDebug() << "Driver Error:" << userQuery.lastError().driverText();
        qDebug() << "Database Error:" << userQuery.lastError().databaseText();
        QMessageBox::critical(this, "Query Error", "Failed to retrieve saving data. " + userQuery.lastError().text());
    }

    qDebug() << "Total income (calculated):" << totalIncome;
    qDebug() << "Total expenses (calculated):" << totalExpenses;
    qDebug() << "Saving (calculated):" << saving;

    *incomeSet << totalIncome;
    *expenseSet << totalExpenses;
    *savingSet << saving;

    QBarSeries *series = new QBarSeries();
    series->append(incomeSet);
    series->append(expenseSet);
    series->append(savingSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Your Financial Summary");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {"Total"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Amount");
    // Ensure range is at least 0 if all values are 0
    double maxVal = qMax(qMax(totalIncome, totalExpenses), saving);
    axisY->setRange(0, (maxVal > 0 ? maxVal : 1000) + 1000); // Prevent 0 range if no data
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartWidget->setChart(chart);
    ui->chartWidget->setRenderHint(QPainter::Antialiasing);

    qDebug() << "Exiting compare::setupChart()";
    qDebug() << "------------------------------------------";
}
