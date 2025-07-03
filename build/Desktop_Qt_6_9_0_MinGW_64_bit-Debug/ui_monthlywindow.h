/********************************************************************************
** Form generated from reading UI file 'monthlywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYWINDOW_H
#define UI_MONTHLYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monthlyWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *monthlyWindow)
    {
        if (monthlyWindow->objectName().isEmpty())
            monthlyWindow->setObjectName("monthlyWindow");
        monthlyWindow->resize(800, 600);
        centralwidget = new QWidget(monthlyWindow);
        centralwidget->setObjectName("centralwidget");
        monthlyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(monthlyWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        monthlyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(monthlyWindow);
        statusbar->setObjectName("statusbar");
        monthlyWindow->setStatusBar(statusbar);

        retranslateUi(monthlyWindow);

        QMetaObject::connectSlotsByName(monthlyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *monthlyWindow)
    {
        monthlyWindow->setWindowTitle(QCoreApplication::translate("monthlyWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monthlyWindow: public Ui_monthlyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYWINDOW_H
