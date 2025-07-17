#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "homewindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QCryptographicHash>
#include <QSettings>
#include <QFormLayout>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QDialog>

loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    ui->pushButton_2->setText("Forgot Password?");
    ui->pushButton_2->setStyleSheet("QPushButton { border: none; color: blue; background: transparent; text-decoration: underline; }");

    QSettings settings("ItsDrishya", "LoginSystem");
    bool wasChecked = settings.value("keep_logged_in", 0).toInt() == 1;
    ui->checkBox->setChecked(wasChecked);

    QString dbFilePath = "C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/centralized.db";
    QFile dbFile(dbFilePath);
    if (!dbFile.exists()) {
        QMessageBox::critical(this, "Database Error", QString("Database file '%1' not found!").arg(dbFilePath));
        return;
    }

    DBconnection = QSqlDatabase::addDatabase("QSQLITE");
    DBconnection.setDatabaseName(dbFilePath);

    if (!DBconnection.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    if (!DBconnection.tables().contains("user")) {
        QMessageBox::critical(this, "Database Error", "Table 'user' not found in database!");
        return;
    }

    this->showMaximized();
}

loginWindow::~loginWindow() {
    delete ui;
}

QString hashPassword(const QString &password) {
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hashed.toHex());
}

void loginWindow::on_pushButton_clicked()
{
    QString Email = ui->lineEdit->text().trimmed();
    QString Password = ui->lineEdit_2->text().trimmed();
    QString hashedPassword = hashPassword(Password);

    ui->lineEdit->setStyleSheet(Email.isEmpty() ? "border: 1px solid red;" : "");
    ui->lineEdit_2->setStyleSheet(Password.isEmpty() ? "border: 1px solid red;" : "");

    if (Email.isEmpty() || Password.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter both your email and password.");
        return;
    }

    QSqlQuery query(DBconnection);
    query.prepare("SELECT * FROM user WHERE email = ? AND password = ?");
    query.addBindValue(Email);
    query.addBindValue(hashedPassword);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to execute query.");
        return;
    }

    if (query.next()) {
        int userId = query.value("id").toInt();
        QString userName = query.value("name").toString();
        QString userEmail = query.value("email").toString();

        QMessageBox::information(this, "Login", "Login successful!");

        bool keepLoggedIn = ui->checkBox->isChecked();
        QSettings settings("ItsDrishya", "LoginSystem");
        settings.setValue("keep_logged_in", keepLoggedIn ? 1 : 0);
        if (keepLoggedIn) {
            settings.setValue("user_id", userId);
            settings.setValue("email", userEmail);
            settings.setValue("user_name", userName);
        }

        homeWindow *home_window = new homeWindow(userName, userEmail, userId, this);
        home_window->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Please check your email and password.");
    }
}

void loginWindow::on_pushButton_2_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Reset Password");
    dialog.setStyleSheet("QDialog { background-color: #f0f0f0; } QLabel, QPushButton { color: black; }");

    QFormLayout *formLayout = new QFormLayout(&dialog);
    QLineEdit *emailEdit = new QLineEdit();
    QLineEdit *petNameEdit = new QLineEdit();
    QLineEdit *dobEdit = new QLineEdit();
    QLineEdit *newPasswordEdit = new QLineEdit();
    QLineEdit *confirmPasswordEdit = new QLineEdit();

    newPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    newPasswordEdit->setVisible(false);
    confirmPasswordEdit->setVisible(false);

    QPushButton *verifyButton = new QPushButton("Verify Identity");
    verifyButton->setStyleSheet("QPushButton { color: black; border: 1px solid black; padding: 4px 12px; background-color: white; } QPushButton:hover { background-color: #e0e0e0; }");

    formLayout->addRow("Email:", emailEdit);
    formLayout->addRow("Pet Name:", petNameEdit);
    formLayout->addRow("DOB (YYYY-MM-DD):", dobEdit);
    formLayout->addWidget(verifyButton);
    formLayout->addRow("New Password:", newPasswordEdit);
    formLayout->addRow("Confirm Password:", confirmPasswordEdit);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    formLayout->addWidget(buttonBox);

    connect(verifyButton, &QPushButton::clicked, &dialog, [&]() {
        QString email = emailEdit->text().trimmed();
        QString petName = petNameEdit->text().trimmed();
        QString dob = dobEdit->text().trimmed();

        if (email.isEmpty() || petName.isEmpty() || dob.isEmpty()) {
            QMessageBox::warning(&dialog, "Missing Fields", "Please fill in all required fields.");
            return;
        }

        QSqlQuery query(DBconnection);
        query.prepare("SELECT * FROM user WHERE email = ? AND dob = ? AND pet_name = ?");
        query.addBindValue(email);
        query.addBindValue(dob);
        query.addBindValue(petName);

        if (query.exec() && query.next()) {
            QMessageBox::information(&dialog, "Verified", "Identity verified. You may enter your new password.");
            newPasswordEdit->setVisible(true);
            confirmPasswordEdit->setVisible(true);
            buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        } else {
            QMessageBox::warning(&dialog, "Mismatch", "Security answers did not match.");
            newPasswordEdit->setVisible(false);
            confirmPasswordEdit->setVisible(false);
            buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        }
    });

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, [&]() {
        QString email = emailEdit->text().trimmed();
        QString newPassword = newPasswordEdit->text().trimmed();
        QString confirmPassword = confirmPasswordEdit->text().trimmed();

        if (newPassword.isEmpty() || confirmPassword.isEmpty()) {
            QMessageBox::warning(&dialog, "Missing Input", "Please enter and confirm your new password.");
            return;
        }

        if (newPassword != confirmPassword) {
            QMessageBox::warning(&dialog, "Mismatch", "Passwords do not match.");
            return;
        }

        QString hashedNewPassword = hashPassword(newPassword);

        QSqlQuery update(DBconnection);
        update.prepare("UPDATE user SET password = ? WHERE email = ?");
        update.addBindValue(hashedNewPassword);
        update.addBindValue(email);

        if (update.exec()) {
            QMessageBox::information(&dialog, "Success", "Password reset successfully.");
            dialog.accept();
        } else {
            QMessageBox::warning(&dialog, "Error", "Failed to update password.");
        }
    });

    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    dialog.exec();
}
