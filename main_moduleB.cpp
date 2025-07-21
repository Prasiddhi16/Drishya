#include <QApplication>
#include "RecordWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyleSheet(R"(
    QLineEdit, QTextEdit, QLabel, QPushButton {
        color: black;
    }
    QLineEdit {
        background-color: white;
    }
    QTextEdit {
        background-color: #f9f9f9;
    }
    QDialog {
        background-color: #ffffff;
        color: black;
    }
    QMessageBox {
        background-color: #f2f2f2;
        color: #2c3e50;
        font-family: Segoe UI;
        font-size: 10pt;
    }
    QMessageBox QLabel {
        color: #2c3e50;
    }
    QMessageBox QPushButton {
        background-color: #e0e0e0;
        padding: 6px 12px;
    }
)");
 RecordWindow w;
    w.show();
    return a.exec();
}
