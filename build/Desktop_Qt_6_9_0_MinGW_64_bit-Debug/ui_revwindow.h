/********************************************************************************
** Form generated from reading UI file 'revwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVWINDOW_H
#define UI_REVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_revWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *revWindow)
    {
        if (revWindow->objectName().isEmpty())
            revWindow->setObjectName("revWindow");
        revWindow->resize(800, 600);
        centralwidget = new QWidget(revWindow);
        centralwidget->setObjectName("centralwidget");
        revWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(revWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        revWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(revWindow);
        statusbar->setObjectName("statusbar");
        revWindow->setStatusBar(statusbar);

        retranslateUi(revWindow);

        QMetaObject::connectSlotsByName(revWindow);
    } // setupUi

    void retranslateUi(QMainWindow *revWindow)
    {
        revWindow->setWindowTitle(QCoreApplication::translate("revWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class revWindow: public Ui_revWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVWINDOW_H
