#include "signwindow.h"
#include "ui_signwindow.h"
#include "welwindow.h"

#include <QMessageBox>
#include <QRegularExpression>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDate>
#include <QDebug>
#include <QDir>

signWindow::signWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signWindow)
{
    ui->setupUi(this);
    ui->lineEdit_3->setPlaceholderText("8 characters and must contain at least 3 integers.");
    ui->lineEdit_4->setPlaceholderText("YYYY-MM-DD");

    DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("centralized.db");

    if (DB_connection.open()) {
        QSqlQuery query(DB_connection);

        query.exec("CREATE TABLE IF NOT EXISTS user ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "name TEXT, "
                   "email TEXT UNIQUE, "
                   "password TEXT, "
                   "dob TEXT, "
                   "pet_name TEXT)");

        query.exec("CREATE TABLE IF NOT EXISTS records ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "user_id INTEGER, "
                   "income_amount REAL, income_source TEXT, income_currency TEXT, "
                   "expense_amount REAL, expense_category TEXT, expense_currency TEXT, "
                   "reference TEXT, review TEXT, timestamp TEXT, "
                   "FOREIGN KEY (user_id) REFERENCES user(id))");

        query.exec("CREATE TABLE IF NOT EXISTS goals ("
                   "goal_id TEXT PRIMARY KEY, "
                   "user_id INTEGER, "
                   "goal_name TEXT, required_amount REAL, downpayment REAL, time_limit TEXT, "
                   "FOREIGN KEY (user_id) REFERENCES user(id))");

        query.exec("CREATE TABLE IF NOT EXISTS review ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "user_id INTEGER, savings REAL, tax REAL, "
                   "FOREIGN KEY (user_id) REFERENCES user(id))");

    } else {
        qDebug() << "DB Error:" << DB_connection.lastError().text();
    }

    this->showMaximized();
}

signWindow::~signWindow()
{
    delete ui;
}

void signWindow::on_pushButton_clicked()
{
    QString name     = ui->lineEdit->text().trimmed();
    QString email    = ui->lineEdit_2->text().trimmed();
    QString password = ui->lineEdit_3->text().trimmed();
    QString dob      = ui->lineEdit_4->text().trimmed();
    QString petName  = ui->lineEdit_5->text().trimmed();

    auto showMessage = [this](QMessageBox::Icon icon, const QString &title, const QString &text) {
        QMessageBox box(this);
        box.setIcon(icon);
        box.setWindowTitle(title);
        box.setText(text);
        box.exec();
    };

    // Validation
    if (name.isEmpty() || email.isEmpty() || password.isEmpty() || dob.isEmpty() || petName.isEmpty()) {
        showMessage(QMessageBox::Warning, "Missing Info", "Please fill in all required fields.");
        return;
    }

    if (!QRegularExpression("^[A-Za-z\\s]+$").match(name).hasMatch()) {
        showMessage(QMessageBox::Warning, "Invalid Name", "Name must contain only letters and spaces.");
        return;
    }

    if (!QRegularExpression(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)").match(email).hasMatch()) {
        showMessage(QMessageBox::Warning, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    if (password.length() < 8 || std::count_if(password.begin(), password.end(), [](const QChar &ch) { return ch.isDigit(); }) < 3) {
        showMessage(QMessageBox::Warning, "Weak Password", "Password must be at least 8 characters and include at least 3 digits.");
        return;
    }

    QDate parsedDob = QDate::fromString(dob, "yyyy-MM-dd");
    QDate today = QDate::currentDate();
    if (!parsedDob.isValid() || parsedDob > today || parsedDob.daysTo(today) / 365 < 10) {
        showMessage(QMessageBox::Warning, "Invalid DOB", "Enter a valid date of birth. You must be at least 10 years old.");
        return;
    }

    if (!DB_connection.isOpen()) DB_connection.open();

    QSqlQuery checkQuery(DB_connection);
    checkQuery.prepare("SELECT COUNT(*) FROM user WHERE email = :email");
    checkQuery.bindValue(":email", email);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        showMessage(QMessageBox::Warning, "Email Exists", "This email is already registered.");
        return;
    }

    QString hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QSqlQuery insertQuery(DB_connection);
    insertQuery.prepare("INSERT INTO user(name, email, password, dob, pet_name) "
                        "VALUES (:name, :email, :password, :dob, :pet)");
    insertQuery.bindValue(":name", name);
    insertQuery.bindValue(":email", email);
    insertQuery.bindValue(":password", hashedPassword);
    insertQuery.bindValue(":dob", dob);
    insertQuery.bindValue(":pet", petName);

    if (!insertQuery.exec()) {
        qDebug() << "Insert Error:" << insertQuery.lastError().text();
        showMessage(QMessageBox::Critical, "Database Error", "Failed to register user.");
        return;
    }

    int userId = insertQuery.lastInsertId().toInt();

    showMessage(QMessageBox::Information, "Success", "User registered successfully!");
    DB_connection.close();

    // Pass email + userId to welcome window
    this->hide();
    wel_window = new welWindow(email, userId, this);
    wel_window->show();
}
