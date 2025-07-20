#include <QApplication>
#include <QSettings>
#include "mainwindow.h"
#include "homewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 🌈 Global Styling: black text on white background for all input fields and dialogs
    a.setStyleSheet(
        "QLineEdit, QTextEdit, QLabel, QPushButton { color: black; }"
        "QLineEdit { background-color: white; }"
        "QTextEdit { background-color: #f9f9f9; }"
        "QDialog { background-color: white; }"
        "QDialog QWidget { background-color: transparent; }"
        );

    // 🔐 Check login persistence
    QSettings settings("ItsDrishya", "LoginSystem");
    int stayLoggedIn = settings.value("keep_logged_in", 0).toInt();
    int userId = settings.value("user_id", 0).toInt();
    QString email = settings.value("email", "").toString();
    QString userName = settings.value("user_name", "").toString();

    if (stayLoggedIn == 1 && userId != 0 && !email.isEmpty() && !userName.isEmpty()) {
        homeWindow *home = new homeWindow(userName, email, userId);
        home->show();
    } else {
        MainWindow *main = new MainWindow();
        main->show();
    }

    return a.exec();
}
