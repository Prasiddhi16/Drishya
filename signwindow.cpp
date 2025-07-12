#include "signwindow.h"
#include "ui_signwindow.h"
#include "welwindow.h"

#include <QMessageBox>
#include <QRegularExpression>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDate>
#include <QDir>
#include <QDebug>

signWindow::signWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signWindow)
{
    ui->setupUi(this);
    ui->lineEdit_3->setPlaceholderText("8 characters and must contain at least 3 integers.");
    ui->lineEdit_4->setPlaceholderText("YYYY-MM-DD");

    DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("unified.db");

    if (DB_connection.open()) {
        QSqlQuery createTable(DB_connection);
        createTable.exec("CREATE TABLE IF NOT EXISTS user ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name TEXT, "
                         "email TEXT UNIQUE, "
                         "password TEXT, "
                         "dob TEXT, "
                         "pet_name TEXT)");
    } else {
        qDebug() << "DB Error:" << DB_connection.lastError().text();
    }
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

    // ✅ Basic Validation
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
    insertQuery.prepare("INSERT INTO user(name, email, password, dob, pet_name) VALUES (:name, :email, :password, :dob, :pet)");
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

    showMessage(QMessageBox::Information, "Success", "User registered successfully!");
    DB_connection.close();

    // ✅ Create user-specific database
    QString baseName = email.section('@', 0, 0);
    QDir dir;
    if (!dir.exists("users")) dir.mkdir("users");

    QString userDbPath = "users/" + baseName + ".db";
    QSqlDatabase userDb = QSqlDatabase::addDatabase("QSQLITE", baseName);
    userDb.setDatabaseName(userDbPath);

    if (userDb.open()) {
        QSqlQuery query(userDb);
        query.exec("CREATE TABLE IF NOT EXISTS records ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "income_amount REAL, income_source TEXT, income_currency TEXT, "
                   "expense_amount REAL, expense_category TEXT, expense_currency TEXT, "
                   "reference TEXT, review TEXT, timestamp TEXT)");

        query.exec("CREATE TABLE IF NOT EXISTS goals ("
                   "goal_id TEXT PRIMARY KEY, "
                   "goal_name TEXT, required_amount REAL, downpayment REAL, time_limit TEXT)");

        query.exec("CREATE TABLE IF NOT EXISTS review ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "u_id INTEGER, savings REAL, tax REAL)");

        userDb.close();
    } else {
        qDebug() << "User DB Create Error:" << userDb.lastError().text();
    }

    // ✅ Proceed to welcome window
    this->hide();
    wel_window = new welWindow(email, this);
    wel_window->show();
}
