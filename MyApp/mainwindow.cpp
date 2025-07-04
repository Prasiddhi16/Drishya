#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setEnabled(false);

    connect(ui->addRecordButton, &QPushButton::clicked, this, &MainWindow::addRecord);

    // Open SQLite database (saved in app directory)
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS records ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "income_amount TEXT,"
            "income_source TEXT,"
            "income_currency TEXT,"
            "expenses_amount TEXT,"
            "expenses_category TEXT,"
            "expenses_currency TEXT,"
            "classification TEXT,"
            "identifier TEXT,"
            "reference TEXT,"
            "review TEXT,"
            "status TEXT,"
            "timestamp TEXT)"
            )) {
        QMessageBox::warning(this, "Table Creation Error", query.lastError().text());
    }
}

MainWindow::~MainWindow()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

void MainWindow::addRecord()
{

    QString incomeAmount = ui->incomeAmountLineEdit->text().trimmed();
    QString incomeSource = ui->incomeSouceComboBox->currentText();
    QString incomeCurrency = ui->currencyComboBox->currentText();

    QString expensesAmount = ui->expensesAmountLineEdit->text().trimmed();
    QString expensesCategory = ui->expensesCategoryComboBox->currentText();
    QString expensesCurrency = ui->currencyComboBox_2->currentText();

    QString classification = ui->classificationComboBox->currentText();
    QString identifier = ui->identifiersLineEdit->text().trimmed();
    QString reference = ui->ReferenceTextEdit->text().trimmed();  // Assumes QTextEdit
    QString review = ui->reviewTextEdit->text().trimmed();        // Assumes QTextEdit
    QString status = ui->statusComboBox->currentText();
    QString timestamp = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    // ✅ Validation: block if any field is empty
    if (incomeAmount.isEmpty() || incomeSource.isEmpty() || incomeCurrency.isEmpty() ||
        expensesAmount.isEmpty() || expensesCategory.isEmpty() || expensesCurrency.isEmpty() ||
        classification.isEmpty() || identifier.isEmpty() || reference.isEmpty() ||
        review.isEmpty() || status.isEmpty())
    {
        QMessageBox::warning(this, "Missing Information", "Please fill all the information before saving.");
        return;
    }

    // Debug log
    qDebug() << "Saving Record:";
    qDebug() << incomeAmount << incomeSource << incomeCurrency;
    qDebug() << expensesAmount << expensesCategory << expensesCurrency;
    qDebug() << classification << identifier << reference << review << status << timestamp;

    // Insert to DB
    QSqlQuery query;
    query.prepare(
        "INSERT INTO records (income_amount, income_source, income_currency, "
        "expenses_amount, expenses_category, expenses_currency, "
        "classification, identifier, reference, review, status, timestamp) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
        );

    query.addBindValue(incomeAmount);
    query.addBindValue(incomeSource);
    query.addBindValue(incomeCurrency);
    query.addBindValue(expensesAmount);
    query.addBindValue(expensesCategory);
    query.addBindValue(expensesCurrency);
    query.addBindValue(classification);
    query.addBindValue(identifier);
    query.addBindValue(reference);
    query.addBindValue(review);
    query.addBindValue(status);
    query.addBindValue(timestamp);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Record added successfully.");

        // Optional: clear form here if needed
        /*
        ui->incomeAmountLineEdit->clear();
        ui->expensesAmountLineEdit->clear();
        ui->identifiersLineEdit->clear();
        ui->ReferenceTextEdit->clear();
        ui->reviewTextEdit->clear();
        ui->incomeSouceComboBox->setCurrentIndex(0);
        ui->expensesCategoryComboBox->setCurrentIndex(0);
        ui->currencyComboBox->setCurrentIndex(0);
        ui->currencyComboBox_2->setCurrentIndex(0);
        ui->classificationComboBox->setCurrentIndex(0);
        ui->statusComboBox->setCurrentIndex(0);
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
        */
    } else {
        QMessageBox::critical(this, "Insert Error", query.lastError().text());
    }
}
