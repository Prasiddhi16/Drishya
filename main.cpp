#include <QApplication>
#include <QSettings>
#include "mainwindow.h"
#include "homewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    // Default styling: black text across core widgets
    a.setStyleSheet("QLineEdit, QTextEdit, QLabel, QPushButton { color: black;}");

    // 🔐 Check login persistence
    QSettings settings("ItsDrishya", "LoginSystem");
    int stayLoggedIn = settings.value("keep_logged_in", 0).toInt();
    int userId = settings.value("user_id", 0).toInt();
    QString email = settings.value("email", "").toString();

    if (stayLoggedIn == 1 && userId != 0) {
        // Launch home window directly
        homeWindow *home = new homeWindow(email, userId);
        home->show();
    } else {
        // Show welcome screen
        MainWindow *main = new MainWindow();
        main->show();
    }

    return a.exec();
}
