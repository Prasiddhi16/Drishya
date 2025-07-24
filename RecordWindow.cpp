
#include "RecordWindow.h"
#include "ui_RecordWindow.h"
#include "visions.h"
#include "review.h"
#include "analysiswindow.h"

#include "profile.h"
#include "loginwindow.h"


#include "Help.h"
#include "homewindow.h"
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
#include <QTableWidget>
#include <QTableWidgetItem>

RecordWindow::RecordWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::RecordWindow),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);
    qApp->setStyleSheet("QDialog, QMessageBox { background-color: white; color: black; }");
    ui->tabWidget->setCurrentIndex(0);  // Show Income tab first
    ui->tabWidget->setStyleSheet(R"(
    QTabBar::tab:selected {
        color: green;     /* Active tab text color */
    }
    QTabBar::tab:!selected {
        color: black;     /* Inactive tab text color */
    }
)");
     this->showMaximized();
    ui->timestamp->setDateTime(QDateTime::currentDateTime());

     QPixmap pix(":/img/img/profileicon.png");
     ui->toolButton->setIcon(QIcon(pix));
     ui->toolButton->setIconSize(ui->toolButton->size());

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
            "reference TEXT, review TEXT, timestamp TEXT)"))) {
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
    connect(buttons[5], &QPushButton::clicked, this, &RecordWindow::openhelp);
    QWidget *contentWidget = new QWidget;
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->addWidget(ui->centralwidget);

    QWidget *mainCentral = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(mainCentral);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(contentWidget);

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
    if (reference.isEmpty() || review.isEmpty() || timestamp.isEmpty()) {
        QMessageBox::warning(this, "Missing Data", "Please fill reference, review, and timestamp.");
        return;
    }
    // Income
    double incomeAmount = 0.0;
    QString finalIncomeSource;
    QString finalIncomeCurrency;

    if (!incomeAmountStr.isEmpty()) {
        bool incomeOk = false;
        incomeAmount = incomeAmountStr.toDouble(&incomeOk);
        if (!incomeOk) {
            QMessageBox::warning(this, "Invalid Income", "Income amount must be a number.");
            return;
        }
        finalIncomeSource = incomeSource.isEmpty() ? QString() : incomeSource;
        finalIncomeCurrency = incomeCurrency.isEmpty() ? QString() : incomeCurrency;
    } else {
        // No income amount entered, ignore other income fields
        finalIncomeSource = QString();
        finalIncomeCurrency = QString();
    }
     // Expense
    double expenseAmount = 0.0;
    QString finalExpenseCategory;
    QString finalExpenseCurrency;

    if (!expenseAmountStr.isEmpty()) {
        bool expenseOk = false;
        expenseAmount = expenseAmountStr.toDouble(&expenseOk);
        if (!expenseOk) {
            QMessageBox::warning(this, "Invalid Expense", "Expense amount must be a number.");
            return;
        }
        finalExpenseCategory = expenseCategory.isEmpty() ? QString() : expenseCategory;
        finalExpenseCurrency = expenseCurrency.isEmpty() ? QString() : expenseCurrency;
    } else {
        // No expense amount entered, ignore other expense fields
        finalExpenseCategory = QString();
        finalExpenseCurrency = QString();
    }
    QSqlQuery query(DB_connection);
    query.prepare("INSERT INTO records (user_id, income_amount, income_source, income_currency, "
                  "expense_amount, expense_category, expense_currency, reference, review, timestamp) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(currentUserId);
    query.addBindValue(incomeAmount);
    query.addBindValue(finalIncomeSource);
    query.addBindValue(finalIncomeCurrency);
    query.addBindValue(expenseAmount);
    query.addBindValue(finalExpenseCategory);
    query.addBindValue(finalExpenseCurrency);
    query.addBindValue(reference);
    query.addBindValue(review);
    query.addBindValue(timestamp);
   if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Record added successfully.");
        emit expenseAdded();
    }
}

bool RecordWindow::showEditDialog(const QString& title, const QString& labelText,
                                  QString& amount, QString& sourceOrCategory, QString& timestamp)
{
    QDialog dialog(this);
    dialog.setWindowTitle(title);

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

void RecordWindow::editIncome() { showIncomeTable(); }
void RecordWindow::editExpense() { showExpenseTable(); }

void RecordWindow::showIncomeTable() {
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Income Entries");
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QTableWidget *table = new QTableWidget(&dialog);
    table->setStyleSheet(R"(
        QTableWidget {
            background-color: white;
            color: black;
            gridline-color: #c0c0c0;
        }
        QHeaderView::section {
            background-color: #f0f0f0;
            color: black;
            font-weight: bold;
            padding: 4px;
            border: 1px solid #dcdcdc;
        }
        QTableWidget QTableCornerButton::section {
            background-color: #f0f0f0;
            border: 1px solid #dcdcdc;
        }
    )");

    QSqlQuery query(DB_connection);
    query.prepare("SELECT id, income_amount, income_source, timestamp FROM records WHERE income_amount IS NOT NULL AND user_id = ?");
    query.addBindValue(currentUserId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", query.lastError().text());
        return;
    }

    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Amount", "Source", "Timestamp", "Edit", "Delete"});
    int row = 0;

    while (query.next()) {
        table->insertRow(row);
        int recordId = query.value(0).toInt();

        table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        table->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));

        QPushButton *editBtn = new QPushButton("Edit");
        editBtn->setStyleSheet("background-color:#bccdb7;");
        table->setCellWidget(row, 3, editBtn);

        QPushButton *deleteBtn = new QPushButton("Delete");
        deleteBtn->setStyleSheet("background-color:#e57373; color:white;");
        table->setCellWidget(row, 4, deleteBtn);

        connect(editBtn, &QPushButton::clicked, this, [=]() {
            QString editableAmount = query.value(1).toString();
            QString editableSource = query.value(2).toString();
            QString editableTimestamp = query.value(3).toString();

            if (showEditDialog("Edit Income", "Source", editableAmount, editableSource, editableTimestamp)) {
                bool valid;
                double amountDouble = editableAmount.toDouble(&valid);
                if (!valid) {
                    QMessageBox::warning(this, "Invalid Input", "Please enter a valid numeric amount.");
                    return;
                }

                QSqlQuery update(DB_connection);
                update.prepare("UPDATE records SET income_amount = ?, income_source = ?, timestamp = ? WHERE id = ?");
                update.addBindValue(amountDouble);
                update.addBindValue(editableSource);
                update.addBindValue(editableTimestamp);
                update.addBindValue(recordId);

                if (!update.exec()) {
                    QMessageBox::critical(this, "Error", "Failed to update income.\n" + update.lastError().text());
                } else {
                    QMessageBox::information(this, "Updated", "Income updated successfully.");
                    table->setItem(row, 0, new QTableWidgetItem(editableAmount));
                    table->setItem(row, 1, new QTableWidgetItem(editableSource));
                    table->setItem(row, 2, new QTableWidgetItem(editableTimestamp));
                }
            }
        });

        connect(deleteBtn, &QPushButton::clicked, this, [=]() {
            if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this income record?") == QMessageBox::Yes) {
                QSqlQuery delQuery(DB_connection);
                delQuery.prepare("DELETE FROM records WHERE id = ?");
                delQuery.addBindValue(recordId);

                if (!delQuery.exec()) {
                    QMessageBox::critical(this, "Error", "Failed to delete record.\n" + delQuery.lastError().text());
                } else {
                    table->removeRow(row);
                    QMessageBox::information(this, "Deleted", "Income record deleted.");
                }
            }
        });

        row++;
    }

    layout->addWidget(table);
    dialog.setLayout(layout);
    dialog.exec();
}
void RecordWindow::showExpenseTable() {
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Expense Entries");
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QTableWidget *table = new QTableWidget(&dialog);
    table->setStyleSheet(R"(
        QTableWidget {
            background-color: white;
            color: black;
            gridline-color: #c0c0c0;
        }
        QHeaderView::section {
            background-color: #f0f0f0;
            color: black;
            font-weight: bold;
            padding: 4px;
            border: 1px solid #dcdcdc;
        }
        QTableWidget QTableCornerButton::section {
            background-color: #f0f0f0;
            border: 1px solid #dcdcdc;
        }
    )");

    QSqlQuery query(DB_connection);
    query.prepare("SELECT id, expense_amount, expense_category, timestamp FROM records WHERE expense_amount IS NOT NULL AND user_id = ?");
    query.addBindValue(currentUserId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", query.lastError().text());
        return;
    }

    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Amount", "Category", "Timestamp", "Edit", "Delete"});
    int row = 0;

    while (query.next()) {
        table->insertRow(row);
        int recordId = query.value(0).toInt();
        table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        table->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));

        QPushButton *editBtn = new QPushButton("Edit");
        editBtn->setStyleSheet("background-color:#bccdb7;");
        table->setCellWidget(row, 3, editBtn);
        QPushButton *deleteBtn = new QPushButton("Delete");
        deleteBtn->setStyleSheet("background-color:#e57373; color:white;");
        table->setCellWidget(row, 4, deleteBtn);
        connect(editBtn, &QPushButton::clicked, this, [=]() {
            QString editableAmount = query.value(1).toString();
            QString editableCategory = query.value(2).toString();
            QString editableTimestamp = query.value(3).toString();
            if (showEditDialog("Edit Expense", "Category", editableAmount, editableCategory, editableTimestamp)) {
                bool valid;
                double amountDouble = editableAmount.toDouble(&valid);
                if (!valid) {
                    QMessageBox::warning(this, "Invalid Input", "Please enter a valid numeric amount.");
                    return;
                }
                 QSqlQuery update(DB_connection);
                update.prepare("UPDATE records SET expense_amount = ?, expense_category = ?, timestamp = ? WHERE id = ?");
                update.addBindValue(amountDouble);
                update.addBindValue(editableCategory);
                update.addBindValue(editableTimestamp);
                update.addBindValue(recordId);

                if (!update.exec()) {
                    QMessageBox::critical(this, "Error", "Failed to update expense.\n" + update.lastError().text());
                } else {
                    QMessageBox::information(this, "Updated", "Expense updated successfully.");
                    table->setItem(row, 0, new QTableWidgetItem(editableAmount));
                    table->setItem(row, 1, new QTableWidgetItem(editableCategory));
                    table->setItem(row, 2, new QTableWidgetItem(editableTimestamp));
                }
            }
        });
        connect(deleteBtn, &QPushButton::clicked, this, [=]() {
            if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this expense record?") == QMessageBox::Yes) {
                QSqlQuery delQuery(DB_connection);
                delQuery.prepare("DELETE FROM records WHERE id = ?");
                delQuery.addBindValue(recordId);

                if (!delQuery.exec()) {
                    QMessageBox::critical(this, "Error", "Failed to delete record.\n" + delQuery.lastError().text());
                } else {
                    table->removeRow(row);
                    QMessageBox::information(this, "Deleted", "Expense record deleted.");
                }
            }
        });
        row++;
    }
     layout->addWidget(table);
    dialog.setLayout(layout);
    dialog.exec();
}
void RecordWindow::openHome() {
    home_window = new homeWindow(currentUserName, currentUserEmail, currentUserId, this);
    home_window->show();
    this->hide();
}
void RecordWindow::openAnalytics() {
    analysisWindow *analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
    this->hide();
}
void RecordWindow::openvisions() {
    Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
    vision_win->show();
    this->hide();
}
void RecordWindow::openreview() {
    review *review_win = new review(currentUserName, currentUserEmail, currentUserId, this);
    review_win->show();
    this->hide();
}
void RecordWindow::on_toolButton_clicked()
{

    int userId = 0;
    QString userEmail = "";

     profile *p = new profile(currentUserId, currentUserEmail, this);
    p->setWindowFlags(Qt::Popup);
    QPoint globalPos = ui->toolButton->mapToGlobal(QPoint(0,ui->toolButton->height()));
    p->move(globalPos);
    p->show();

}



void RecordWindow::openhelp()
{
    Help *help_win =new Help(currentUserName, currentUserEmail, currentUserId, this);
    help_win->show();
}

