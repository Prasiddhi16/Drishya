/********************************************************************************
** Form generated from reading UI file 'weeklywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKLYWINDOW_H
#define UI_WEEKLYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weeklyWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *weeklyWindow)
    {
        if (weeklyWindow->objectName().isEmpty())
            weeklyWindow->setObjectName("weeklyWindow");
        weeklyWindow->resize(800, 600);
        centralwidget = new QWidget(weeklyWindow);
        centralwidget->setObjectName("centralwidget");
        weeklyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(weeklyWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        weeklyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(weeklyWindow);
        statusbar->setObjectName("statusbar");
        weeklyWindow->setStatusBar(statusbar);

        retranslateUi(weeklyWindow);

        QMetaObject::connectSlotsByName(weeklyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *weeklyWindow)
    {
        weeklyWindow->setWindowTitle(QCoreApplication::translate("weeklyWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class weeklyWindow: public Ui_weeklyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKLYWINDOW_H
