/********************************************************************************
** Form generated from reading UI file 'welwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELWINDOW_H
#define UI_WELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *welWindow)
    {
        if (welWindow->objectName().isEmpty())
            welWindow->setObjectName("welWindow");
        welWindow->resize(807, 567);
        welWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(175, 255, 242);"));
        centralwidget = new QWidget(welWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);"));

        verticalLayout_3->addWidget(pushButton, 0, Qt::AlignmentFlag::AlignRight);

        welWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(welWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 807, 17));
        welWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(welWindow);
        statusbar->setObjectName("statusbar");
        welWindow->setStatusBar(statusbar);

        retranslateUi(welWindow);

        QMetaObject::connectSlotsByName(welWindow);
    } // setupUi

    void retranslateUi(QMainWindow *welWindow)
    {
        welWindow->setWindowTitle(QCoreApplication::translate("welWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("welWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; color:#000000;\">WELCOME!</span></p><p align=\"center\"><span style=\" font-size:16pt; font-style:italic; color:#0b0c39;\">Let's Trace,Track And Thrive.</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("welWindow", "Next >", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welWindow: public Ui_welWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELWINDOW_H
