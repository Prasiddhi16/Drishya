#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QDebug>

loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    QString dbFilePath = "C:/Users/Lenovo/OneDrive/Documents/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/Qtdata.db";

    QFile dbFile(dbFilePath);
    if (!dbFile.exists()) {
        QString errMsg = QString("Database file '%1' not found!").arg(dbFilePath);
        qDebug() << errMsg;
        QMessageBox::critical(this, "Database Error", errMsg);
        return;
    }

    DBconnection = QSqlDatabase::addDatabase("QSQLITE");
    DBconnection.setDatabaseName(dbFilePath);

    if (DBconnection.open()) {
        qDebug() << "Database is connected.";
        qDebug() << "Driver in use:" << DBconnection.driverName();

        QStringList tables = DBconnection.tables();
        qDebug() << "Tables in DB:" << tables;

        if (!tables.contains("user")) {
            QString errMsg = "Table 'user' not found in database!";
            qDebug() << errMsg;
            QMessageBox::critical(this, "Database Error", errMsg);
            return;
        }
    } else {
        qDebug() << "Database not connected";
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }
    QSqlQuery autoLogin(DBconnection);
    autoLogin.prepare("SELECT email FROM user WHERE keep_logged_in = 1");

    if (autoLogin.exec() && autoLogin.next()) {
        QString rememberedUser = autoLogin.value(0).toString();
        qDebug() << "Auto-login for:" << rememberedUser;

        homeWindow *home_window = new homeWindow();
        home_window->show();
        this->hide();
    }

}

loginWindow::~loginWindow()
{
    delete ui;
}
void loginWindow::on_checkBox_stateChanged(int state)
{
    qDebug() << (state == Qt::Checked ? "Checkbox checked." : "Checkbox unchecked.");



}



void loginWindow::on_pushButton_clicked()
{

        QString Email = ui->lineEdit->text();
        QString Password = ui->lineEdit_2->text();
        bool keepLoggedIn = ui->checkBox->isChecked();

        qDebug() << "Email:" << Email << ", Password:" << Password;
        qDebug() << "Checkbox checked?" << keepLoggedIn;

        QSqlQuery query(DBconnection);
        query.prepare("SELECT * FROM user WHERE email = ? AND password = ?");
        query.addBindValue(Email);
        query.addBindValue(Password);

        if (!query.exec()) {
            qDebug() << "Query error:" << query.lastError().text();
            QMessageBox::warning(this, "Error", "Failed to execute query.");
            return;
        }

        if (query.next()) {
            // We have a valid user. Update keep_logged_in value:
            QSqlQuery update(DBconnection);
            update.prepare("UPDATE user SET keep_logged_in = :keep WHERE email = :email");
            update.bindValue(":keep", keepLoggedIn ? 1 : 0);
            update.bindValue(":email", Email);

            if (!update.exec()) {
                qDebug() << "Failed to update keep_logged_in:" << update.lastError().text();
            } else {
                qDebug() << "keep_logged_in updated. Rows affected:" << update.numRowsAffected();
            }

            QMessageBox::information(this, "Login", "Login successful!");
            homeWindow *home_window = new homeWindow(this);
            home_window->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Login Failed", "Please check your email and password.");
        }
    }
   /* if (UserFindCount == 1) {
        QMessageBox::information(this, "Login", "Login successful!");
    } else {
        QMessageBox::warning(this, "Login Failed", "Please check your email and password.");
    }
void loginWindow::on_checkBox_clicked()

{

    QString Email = ui->lineEdit->text();
    int UserFindCount = 0;
    if (UserFindCount == 1) {
        // Update keep_logged_in if checkbox is checked
        bool keepLoggedIn = ui->checkBox->isChecked();

        QSqlQuery update(DBconnection);
        update.prep
    }


are("UPDATE user SET keep_logged_in = :keep WHERE email = :email");
        update.bindValue(":keep", keepLoggedIn ? 1 : 0);
        update.bindValue(":email", Email);
        //update.exec();

        QMessageBox::information(this, "Login", "Login successful!");

        // Load main window here
        homeWindow *home_window = new homeWindow();
        home_window->show();
        this->close();
    }


}


void loginWindow::on_checkBox_stateChanged(int state)
{
    if (state == Qt::Checked) {
        qDebug() << "Checkbox is checked.";
    } else {
        qDebug() << "Checkbox is not checked.";
    }

    QString Email = ui->lineEdit->text();
    int UserFindCount = 0;
    if (UserFindCount == 1) {
        // Update keep_logged_in if checkbox is checked
        bool keepLoggedIn = ui->checkBox->isChecked();

        QSqlQuery update(DBconnection);
        update.prepare("UPDATE user SET keep_logged_in = :keep WHERE email = :email");
        update.bindValue(":keep", keepLoggedIn ? 1 : 0);
        update.bindValue(":email", Email);
        update.exec();
        if (!update.exec()) {
            qDebug() << "Update failed:" << update.lastError().text();
        }


        QMessageBox::information(this, "Login", "Login successful!");

        // Load main window here
        homeWindow *home_window = new homeWindow();
        home_window->show();
        this->close();
    }
*/




