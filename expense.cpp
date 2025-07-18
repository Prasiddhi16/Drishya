#include "expense.h"
#include "ui_expense.h"
#include "graph.h" // Include graph.h to create graph objects
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QMessageBox> // For user feedback messages
#include <QDateTime>   // For timestamping records
#include <QLineEdit>   // Assuming QLineEdit for input

expense::expense(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::expense)
{
    qDebug() << "Expense: Entering constructor.";
    ui->setupUi(this);
    this->resize(800, 600); // Set a default size for the window
    qDebug() << "Expense: setupUi completed and window resized.";
}

expense::~expense()
{
    qDebug() << "Expense: Entering destructor.";
    delete ui;
    qDebug() << "Expense: Destructor completed.";
}

void expense::on_pushButton_clicked()
{
    qDebug() << "------------------------------------------";
    qDebug() << "Entering expense::on_pushButton_clicked()";

    // Get the existing database connection.
    QSqlDatabase db = QSqlDatabase::database("MainConnection");
    if (!db.isValid() || !db.isOpen()) {
        qDebug() << "ERROR: Database connection is not valid or not open in expense::on_pushButton_clicked()!";
        qDebug() << "Error:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Cannot connect to the database. Please ensure it's set up correctly.");
        return;
    }

    // --- 1. Get user input for Monthly Income and Saving and clean it ---
    QString incomeText = ui->monthlyIncomeLineEdit->text();
    QString savingText = ui->savingLineEdit->text();

    // Remove any non-numeric characters (except decimal point and sign)
    incomeText.removeIf([](QChar c){ return !c.isDigit() && c != '.'; });
    savingText.removeIf([](QChar c){ return !c.isDigit() && c != '.'; });

    bool incomeOk, savingOk;
    double monthlyIncome = incomeText.toDouble(&incomeOk);
    double newSaving = savingText.toDouble(&savingOk);

    if (!incomeOk || !savingOk) {
        QMessageBox::warning(this, "Input Error", "Please enter valid numeric values for Monthly Income and Saving. (e.g., 500.00, not ₹500.00)");
        qDebug() << "Input Error: Invalid numeric values for income or saving after cleaning.";
        qDebug() << "Cleaned Income Text:" << incomeText << "Converted OK:" << incomeOk;
        qDebug() << "Cleaned Saving Text:" << savingText << "Converted OK:" << savingOk;
        return;
    }

    // --- 2. Insert/Update Monthly Income in 'records' table ---
    QSqlQuery insertIncomeQuery(db);
    QString insertIncomeSql = "INSERT INTO records (income_amount, expenses_amount, timestamp) VALUES (:income, 0, :timestamp)";
    insertIncomeQuery.prepare(insertIncomeSql);
    insertIncomeQuery.bindValue(":income", monthlyIncome);
    insertIncomeQuery.bindValue(":timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));

    qDebug() << "Attempting to insert monthly income: " << monthlyIncome;
    if (!insertIncomeQuery.exec()) {
        qDebug() << "ERROR: Failed to insert monthly income into 'records' table!";
        qDebug() << "SQL Error:" << insertIncomeQuery.lastError().text();
        QMessageBox::critical(this, "Database Write Error", "Failed to record monthly income. " + insertIncomeQuery.lastError().text());
        return;
    } else {
        qDebug() << "Successfully inserted monthly income: " << monthlyIncome;
    }

    // --- 3. Update Saving in 'user' table ---
    QSqlQuery updateSavingQuery(db);
    QString updateSavingSql = "UPDATE user SET Saving = :saving WHERE uid = 1";
    updateSavingQuery.prepare(updateSavingSql);
    updateSavingQuery.bindValue(":saving", newSaving);

    qDebug() << "Attempting to update saving to: " << newSaving;
    if (!updateSavingQuery.exec()) {
        qDebug() << "ERROR: Failed to update saving in 'user' table!";
        qDebug() << "SQL Error:" << updateSavingQuery.lastError().text();
        QMessageBox::critical(this, "Database Write Error", "Failed to update saving. " + updateSavingQuery.lastError().text());
        return;
    } else {
        qDebug() << "Successfully updated saving to: " << newSaving;
    }

    // --- 4. Now, query all data to plot the graph ---
    double totalIncome = 0;
    double totalExpenses = 0;
    double saving = 0;

    // Query 1: Get total income and expenses from 'records' table
    QSqlQuery recordsQuery(db);
    QString recordsQueryString = "SELECT income_amount, expenses_amount FROM records";
    qDebug() << "Executing query for all records (after insert):" << recordsQueryString;

    if (recordsQuery.exec(recordsQueryString)) {
        qDebug() << "Query for 'records' executed successfully.";
        QSqlRecord record = recordsQuery.record();
        int incomeIndex = record.indexOf("income_amount");
        int expensesIndex = record.indexOf("expenses_amount");

        if (incomeIndex == -1 || expensesIndex == -1) {
            qDebug() << "ERROR: 'income_amount' or 'expenses_amount' column not found in 'records' table (after insert)!";
            QStringList fieldNames;
            for (int i = 0; i < record.count(); ++i) {
                fieldNames << record.fieldName(i);
            }
            qDebug() << "Available fields in 'records' table:" << fieldNames;
            QMessageBox::warning(this, "Data Error", "Required columns missing in 'records' table for graphing.");
            return;
        }

        while (recordsQuery.next()) {
            totalIncome += recordsQuery.value(incomeIndex).toDouble();
            totalExpenses += recordsQuery.value(expensesIndex).toDouble();
            qDebug() << "Fetched income record for graph:" << recordsQuery.value(incomeIndex).toDouble()
                     << ", expenses record for graph:" << recordsQuery.value(expensesIndex).toDouble();
        }
        if (!recordsQuery.first() && recordsQuery.isSelect()) {
            qDebug() << "Query for 'records' executed successfully, but returned 0 rows for graphing.";
        } else if (recordsQuery.isSelect()) {
            qDebug() << "Query for 'records' executed successfully, and rows were processed for graphing.";
        }

    } else {
        qDebug() << "ERROR: Query for 'records' table FAILED to execute (after insert)!";
        qDebug() << "SQL Error:" << recordsQuery.lastError().text();
        QMessageBox::critical(this, "Query Error", "Failed to retrieve income/expenses data for graphing. " + recordsQuery.lastError().text());
        return;
    }

    // Query 2: Get saving from 'user' table (after update)
    QSqlQuery userQuery(db);
    QString userQueryString = "SELECT Saving FROM user WHERE uid = 1";
    qDebug() << "Executing query for user saving (after update):" << userQueryString;

    if (userQuery.exec(userQueryString)) {
        qDebug() << "Query for 'user' executed successfully.";
        QSqlRecord userRecord = userQuery.record();
        int savingIndex = userRecord.indexOf("Saving");

        if (savingIndex == -1) {
            qDebug() << "ERROR: 'Saving' column not found in 'user' table (after update)!";
            QStringList fieldNames;
            for (int i = 0; i < userRecord.count(); ++i) {
                fieldNames << userRecord.fieldName(i);
            }
            qDebug() << "Available fields in 'user' table:" << fieldNames;
            QMessageBox::warning(this, "Data Error", "Required 'Saving' column missing in 'user' table for graphing.");
        }

        if (userQuery.next()) {
            if (savingIndex != -1) {
                saving = userQuery.value(savingIndex).toDouble();
                qDebug() << "Fetched saving for graph:" << saving;
            } else {
                qDebug() << "Skipping saving value fetch due to missing column.";
            }
        } else {
            qDebug() << "Query for 'user' executed successfully, but returned 0 rows (no user with uid=1 found or no saving data for graph).";
        }
    } else {
        qDebug() << "ERROR: Query for 'user' table FAILED to execute (after update)!";
        qDebug() << "SQL Error:" << userQuery.lastError().text();
        QMessageBox::critical(this, "Query Error", "Failed to retrieve saving data for graphing. " + userQuery.lastError().text());
    }

    qDebug() << "Total Income (Final for Graph):" << totalIncome;
    qDebug() << "Total Expenses (Final for Graph):" << totalExpenses;
    qDebug() << "Saving (Final for Graph):" << saving;

    // Create and show the graph window, passing the actual data
    qDebug() << "Expense: Creating new graph window.";
    Graph = new graph(this, totalIncome, totalExpenses, saving);
    qDebug() << "Expense: Showing graph window.";
    Graph->show();

    qDebug() << "Exiting expense::on_pushButton_clicked()";
    qDebug() << "------------------------------------------";
}
