/*#include "expense.h"
#include "ui_expense.h"
#include "graph.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

expense::expense(const QString &userEmail, int userId, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::expense),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    qDebug() << "Expense: Entering constructor.";
    ui->setupUi(this);
    this->resize(800, 600);
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

    QSqlDatabase db = QSqlDatabase::database("MainConnection");
    if (!db.isValid() || !db.isOpen()) {
        qDebug() << "ERROR: Database connection is not valid or not open!";
        QMessageBox::critical(this, "Database Error", "Cannot connect to the database.");
        return;
    }

    QString incomeText = ui->monthlyIncomeLineEdit->text().remove(QRegExp("[^0-9\\.]"));
    QString savingText = ui->savingLineEdit->text().remove(QRegExp("[^0-9\\.]"));

    bool incomeOk, savingOk;
    double monthlyIncome = incomeText.toDouble(&incomeOk);
    double newSaving = savingText.toDouble(&savingOk);

    if (!incomeOk || !savingOk) {
        QMessageBox::warning(this, "Input Error", "Enter valid numeric values for income and saving.");
        return;
    }

    QSqlQuery insertIncomeQuery(db);
    insertIncomeQuery.prepare("INSERT INTO records (income_amount, expenses_amount, timestamp) VALUES (:income, 0, :timestamp)");
    insertIncomeQuery.bindValue(":income", monthlyIncome);
    insertIncomeQuery.bindValue(":timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));

    if (!insertIncomeQuery.exec()) {
        QMessageBox::critical(this, "Write Error", "Failed to insert income. " + insertIncomeQuery.lastError().text());
        return;
    }

    QSqlQuery updateSavingQuery(db);
    updateSavingQuery.prepare("UPDATE user SET Saving = :saving WHERE uid = :uid");
    updateSavingQuery.bindValue(":saving", newSaving);
    updateSavingQuery.bindValue(":uid", currentUserId);

    if (!updateSavingQuery.exec()) {
        QMessageBox::critical(this, "Write Error", "Failed to update saving. " + updateSavingQuery.lastError().text());
        return;
    }

    double totalIncome = 0, totalExpenses = 0, saving = 0;

    QSqlQuery recordsQuery(db);
    if (recordsQuery.exec("SELECT income_amount, expenses_amount FROM records")) {
        while (recordsQuery.next()) {
            totalIncome += recordsQuery.value("income_amount").toDouble();
            totalExpenses += recordsQuery.value("expenses_amount").toDouble();
        }
    } else {
        QMessageBox::critical(this, "Query Error", "Could not retrieve records. " + recordsQuery.lastError().text());
        return;
    }

    QSqlQuery userQuery(db);
    userQuery.prepare("SELECT Saving FROM user WHERE uid = :uid");
    userQuery.bindValue(":uid", currentUserId);
    if (userQuery.exec() && userQuery.next()) {
        saving = userQuery.value("Saving").toDouble();
    } else {
        QMessageBox::critical(this, "Query Error", "Could not retrieve saving. " + userQuery.lastError().text());
    }

    Graph = new graph();
    Graph->show();

    qDebug() << "Exiting expense::on_pushButton_clicked()";
    qDebug() << "------------------------------------------";
}
*/
