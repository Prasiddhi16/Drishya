#include "RecordWindow.h"
#include "ui_RecordWindow.h"
#include "visions.h"
#include"review.h"
#include"analysiswindow.h"
//#include "Help.h"
#include"homewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDir>

RecordWindow::RecordWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::RecordWindow),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->timestamp->setDateTime(QDateTime::currentDateTime());

    QString exeDir = QCoreApplication::applicationDirPath();
    QString dbFilePath = QDir(exeDir).absoluteFilePath("../centralized.db");

    qDebug() << "Executable Directory:" << exeDir;
    qDebug() << "Resolved DB Path:" << dbFilePath;
    qDebug() << "DB exists:" << QFile::exists(dbFilePath);

    if (!QFile::exists(dbFilePath)) {
        QMessageBox::critical(this, "Database Error",
                              QString("Database file not found at:\n%1").arg(dbFilePath));
        return;
    }

    if (QSqlDatabase::contains("login_connection")) {
        DB_connection = QSqlDatabase::database("login_connection");
    } else {
        DB_connection = QSqlDatabase::addDatabase("QSQLITE", "login_connection");
        DB_connection.setDatabaseName(dbFilePath);
    }

    if (!DB_connection.open()) {
        qDebug() << "DB open error:" << DB_connection.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to open database. Make sure it's not locked or corrupted.\n\n"
                                  + DB_connection.lastError().text());
        return;
    }
    qDebug() << "Database opened successfully.";

    // Ensure table exists
    QSqlQuery query(DB_connection);

    if (!query.exec(QStringLiteral(
            "CREATE TABLE IF NOT EXISTS records ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER, "
            "income_amount REAL, income_source TEXT, income_currency TEXT, "
            "expense_amount REAL, expense_category TEXT, expense_currency TEXT, "
            "reference TEXT, review TEXT, timestamp TEXT)"
            ))) {
        qDebug() << "Table creation error:" << query.lastError().text();
    }

    // UI nav layout
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Segoe UI", 10, QFont::Bold);
    QList<QPushButton*> buttons = {
        new QPushButton("🏠 Home"),
        new QPushButton("➕ Add Records"),
        new QPushButton("📈 Analytics"),
        new QPushButton("🎯 Goals"),
        new QPushButton("📋 Review"),
        new QPushButton("❓ Help")
    };
    for (auto btn : buttons) {
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setStyleSheet("color: #2c3e50; background-color: #e0e0e0; border: none; padding: 8px;");
        navLayout->addWidget(btn);
    }
    connect(buttons[0], &QPushButton::clicked, this, &RecordWindow::openHome);
    connect(buttons[2], &QPushButton::clicked, this, &RecordWindow::openAnalytics);
    connect(buttons[3], &QPushButton::clicked, this, &RecordWindow::openvisions);
    connect(buttons[4], &QPushButton::clicked, this, &RecordWindow::openreview);

    QWidget *contentWidget = new QWidget;
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->addWidget(ui->centralwidget);

    QWidget *mainCentral = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(mainCentral);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(contentWidget);
    mainCentral->setLayout(mainLayout);

    this->setCentralWidget(mainCentral);

    connect(ui->addRecordButton, &QPushButton::clicked, this, &RecordWindow::addRecord);
    connect(ui->editIncomeButton, &QPushButton::clicked, this, &RecordWindow::editIncome);
    connect(ui->editExpenseButton, &QPushButton::clicked, this, &RecordWindow::editExpense);
}

RecordWindow::~RecordWindow()
{
    delete ui;
}

void RecordWindow::addRecord()
{
    QString incomeAmountStr = ui->incomeAmount->text().trimmed();
    QString incomeSource = ui->incomeSource->currentText().trimmed();
    QString incomeCurrency = ui->incomeCurrency->currentText().trimmed();

    QString expenseAmountStr = ui->expenseAmount->text().trimmed();
    QString expenseCategory = ui->expenseCategory->currentText().trimmed();
    QString expenseCurrency = ui->expenseCurrency->currentText().trimmed();

    QString reference = ui->referenceNumber->text().trimmed();
    QString review = ui->review->text().trimmed();
    QString timestamp = ui->timestamp->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    bool allFieldsFilled =
        !incomeAmountStr.isEmpty() && !incomeSource.isEmpty() && !incomeCurrency.isEmpty() &&
        !expenseAmountStr.isEmpty() && !expenseCategory.isEmpty() && !expenseCurrency.isEmpty() &&
        !reference.isEmpty() && !review.isEmpty() && !timestamp.isEmpty();

    // Check if amounts are valid numbers
    bool incomeOk, expenseOk;
    double incomeAmount = incomeAmountStr.toDouble(&incomeOk);
    double expenseAmount = expenseAmountStr.toDouble(&expenseOk);

    if (!allFieldsFilled) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Missing Data");
        msgBox.setText("Please fill all income, expense, reference, review, and timestamp fields.");

        msgBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #2c3e50;  /* Dark navy background */
        }
        QLabel {
            color: #ecf0f1;             /* Light elegant text */
            font-weight: bold;
            font-family: 'Segoe UI';
            font-size: 10pt;
        }
        QPushButton {
            background-color: #ecf0f1;  /* Light button */
            color: #2c3e50;             /* Dark button text */
            padding: 6px 14px;
            border: none;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #d0d3d4;
        }
    )");

        msgBox.exec();
        return;
    }
    if (!incomeOk || !expenseOk) {
        QMessageBox::warning(this, "Invalid Amount", "Please enter valid numeric values for amounts.");
        return;
    }
    QSqlQuery query(DB_connection);

    query.prepare("INSERT INTO records (user_id, income_amount, income_source, income_currency, "
                  "expense_amount, expense_category, expense_currency, reference, review, timestamp) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(currentUserId);
    query.addBindValue(incomeAmount);
    query.addBindValue(incomeSource);
    query.addBindValue(incomeCurrency);
    query.addBindValue(expenseAmount);
    query.addBindValue(expenseCategory);
    query.addBindValue(expenseCurrency);
    query.addBindValue(reference);
    query.addBindValue(review);
    query.addBindValue(timestamp);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
    else{
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Success");
        msgBox.setText("Record added successfully.");



        msgBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #2c3e50;  /* Dark navy background */
        }
        QLabel {
            color: #ecf0f1;             /* Light elegant text */
            font-weight: bold;
            font-family: 'Segoe UI';
            font-size: 10pt;
        }
        QPushButton {
            background-color: #ecf0f1;  /* Light button */
            color: #2c3e50;             /* Dark button text */
            padding: 6px 14px;
            border: none;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #d0d3d4;
        }
)"
                             );

        msgBox.exec();
        emit expenseAdded();
    }
}

bool RecordWindow::showEditDialog(const QString& title, const QString& labelText,
                                  QString& amount, QString& sourceOrCategory, QString& timestamp)
{
    QDialog dialog(this);
    dialog.setWindowTitle(title);

    dialog.setStyleSheet(R"(
    QDialog {
        background-color: #ffffff; /* White background for dialog */
    }
    QLabel {
        background-color: transparent; /* Fix: ensures label doesn't appear with dark bg */
        color: #2c3e50;                /* Dark navy text */
        font-weight: bold;
        font-family: 'Segoe UI';
        font-size: 10pt;
    }
    QLineEdit, QComboBox, QDateTimeEdit {
        background-color: #f5f5f5;     /* Light gray input background */
        color: #2c3e50;
        padding: 5px;
        border: 1px solid #ccc;
        border-radius: 5px;
    }
    QPushButton {
        background-color: #2c3e50;     /* Dark blue button */
        color: #ffffff;
        padding: 6px 14px;
        border: none;
        border-radius: 5px;
    }
    QPushButton:hover {
        background-color: #1c2833;     /* Darker on hover */
    }
)");

    QFormLayout* formLayout = new QFormLayout(&dialog);

    QLineEdit* amountEdit = new QLineEdit(amount);

    QComboBox* sourceEdit = new QComboBox();
    if (labelText == "Category") {
        for (int i = 0; i < ui->expenseCategory->count(); ++i) {
            sourceEdit->addItem(ui->expenseCategory->itemText(i));
        }
    } else {
        for (int i = 0; i < ui->incomeSource->count(); ++i) {
            sourceEdit->addItem(ui->incomeSource->itemText(i));
        }
    }
    sourceEdit->setCurrentText(sourceOrCategory);

    QDateTimeEdit* timeEdit = new QDateTimeEdit(QDateTime::fromString(timestamp, "yyyy-MM-dd hh:mm:ss"));
    timeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    timeEdit->setCalendarPopup(true);

    formLayout->addRow("Amount:", amountEdit);
    formLayout->addRow(labelText + ":", sourceEdit);
    formLayout->addRow("Timestamp:", timeEdit);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    formLayout->addWidget(buttonBox);

    QObject::connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        amount = amountEdit->text().trimmed();
        sourceOrCategory = sourceEdit->currentText().trimmed();
        timestamp = timeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        return true;
    }

    return false;
}

void RecordWindow::editIncome()
{
    QSqlQuery query(DB_connection);
    // Prepare the query string to fetch the latest income record
    query.prepare("SELECT id, income_amount, income_source, timestamp "
                  "FROM records WHERE income_amount IS NOT NULL "
                  "ORDER BY id DESC LIMIT 1");

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "No Record", "No income record found.");
        return;
    }

    int id = query.value(0).toInt();
    QString amount = query.value(1).toString();
    QString source = query.value(2).toString();
    QString timestamp = query.value(3).toString();

    if (showEditDialog("Edit Income", "Source", amount, source, timestamp)) {
        bool valid;
        double amountDouble = amount.toDouble(&valid);
        if (!valid) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid numeric amount.");
            return;
        }

        QSqlQuery update(DB_connection);
        update.prepare("UPDATE records SET income_amount = ?, income_source = ?, timestamp = ? WHERE id = ?");
        update.addBindValue(amountDouble);
        update.addBindValue(source);
        update.addBindValue(timestamp);
        update.addBindValue(id);

        if (!update.exec()) {
            QMessageBox::critical(this, "Error", "Failed to update income.\n" + update.lastError().text());
        } else {
            QMessageBox::information(this, "Updated", "Income updated successfully.");

            // Update UI fields
            ui->incomeAmount->setText(amount);
            ui->incomeSource->setCurrentText(source);
            ui->timestamp->setDateTime(QDateTime::fromString(timestamp, "yyyy-MM-dd hh:mm:ss"));
        }
    }
}

void RecordWindow::editExpense()
{
    QSqlQuery query(DB_connection);
    // Prepare the query string to fetch the latest expense record
    query.prepare("SELECT id, expense_amount, expense_category, timestamp "
                  "FROM records WHERE expense_amount IS NOT NULL "
                  "ORDER BY id DESC LIMIT 1");

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "No Record", "No expense record found.");
        return;
    }

    int id = query.value(0).toInt();
    QString amount = query.value(1).toString();
    QString category = query.value(2).toString();
    QString timestamp = query.value(3).toString();

    if (showEditDialog("Edit Expense", "Category", amount, category, timestamp)) {
        bool valid;
        double amountDouble = amount.toDouble(&valid);
        if (!valid) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid numeric amount.");
            return;
        }

        QSqlQuery update(DB_connection);
        update.prepare("UPDATE records SET expense_amount = ?, expense_category = ?, timestamp = ? WHERE id = ?");
        update.addBindValue(amountDouble);
        update.addBindValue(category);
        update.addBindValue(timestamp);
        update.addBindValue(id);

        if (!update.exec()) {
            QMessageBox::critical(this, "Error", "Failed to update expense.\n" + update.lastError().text());
        } else {
            QMessageBox::information(this, "Updated", "Expense updated successfully.");

            // Update UI fields
            ui->expenseAmount->setText(amount);
            ui->expenseCategory->setCurrentText(category);
            ui->timestamp->setDateTime(QDateTime::fromString(timestamp, "yyyy-MM-dd hh:mm:ss"));
        }
    }
}

    void RecordWindow::openHome()
    {

        home_window = new homeWindow(currentUserName,currentUserEmail, currentUserId, this);


        home_window->show();
        this->hide();
    }
    void RecordWindow::openAnalytics()
    {
        analysisWindow *analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
        analysis_window->show();
        this->hide();
    }
    void RecordWindow::openvisions()
    {
        Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
        vision_win->show();
        this->hide();
    }
    void RecordWindow::openreview()
    {
        review *review_win=new review(currentUserName, currentUserEmail, currentUserId, this);
        review_win->show();
        this->hide();
    }


