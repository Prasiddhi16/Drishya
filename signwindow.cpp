#include "signwindow.h"
#include "ui_signwindow.h"
#include<QMessageBox>
signWindow::signWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signWindow)
{
    ui->setupUi(this);
    DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("Qtdata.db");

    if (DB_connection.open()) {
        qDebug() << "Database is connected.";

        QSqlQuery createTable(DB_connection);
        if (!createTable.exec("CREATE TABLE IF NOT EXISTS user ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "name TEXT, "
                              "email TEXT, "
                              "password TEXT)")) {
            qDebug() << "Table creation failed:" << createTable.lastError().text();
        } else {
            qDebug() << "Table ensured to exist.";
        }

        // Debug table structure
        QSqlQuery schemaQuery(DB_connection);
        schemaQuery.exec("PRAGMA table_info(user)");
        qDebug() << "=== USER TABLE SCHEMA ===";
        while (schemaQuery.next()) {
            qDebug() << "Column:" << schemaQuery.value(1).toString();
        }

    } else {
        qDebug() << "Error:" << DB_connection.lastError().text();
    }
}

signWindow::~signWindow()
{
    delete ui;
}



    void signWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString email = ui->lineEdit_2->text().trimmed();
    QString password = ui->lineEdit_3->text().trimmed();

    // Check if any field is empty
    if (name.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Incomplete Details", "Please enter all the details.");
        return;
    }



    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    QRegularExpressionMatch match = emailRegex.match(email);

    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }
 if (password.length() < 8) {
        QMessageBox::warning(this, "Weak Password", "Password must be at least 8 characters long.");
        return;
    }

    // Count digits
    int digitCount = 0;
    for (const QChar &ch : password) {
        if (ch.isDigit())
            digitCount++;
    }

    if (digitCount < 3) {
        QMessageBox::warning(this, "Weak Password", "Password must contain at least 3 digits.");
        return;
    }


    if (!DB_connection.isOpen()) {
        DB_connection.open();
    }

    QSqlDatabase::database().transaction();

    QSqlQuery QueryInsertData(DB_connection);
    QueryInsertData.prepare("INSERT INTO user(name, email, password) VALUES(:name, :email, :password)");
    QueryInsertData.bindValue(":name", name);
    QueryInsertData.bindValue(":email", email);
    QueryInsertData.bindValue(":password", password);

    if (!QueryInsertData.exec()) {
        qDebug() << "Insert failed:" << QueryInsertData.lastError().text();
        QSqlDatabase::database().rollback();
    } else {
        qDebug() << "Insert successful";
        QSqlDatabase::database().commit();
        QMessageBox::information(this, "Success", "User registered successfully!");
    }

    DB_connection.close();
    wel_window = new welWindow(this);
    wel_window->show();
}











