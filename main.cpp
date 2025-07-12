#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    // Set default text color to black for relevant widgets
    a.setStyleSheet("QLineEdit, QTextEdit, QLabel, QPushButton { color: black;}");

    MainWindow w;
    w.show();

    return a.exec();
}
