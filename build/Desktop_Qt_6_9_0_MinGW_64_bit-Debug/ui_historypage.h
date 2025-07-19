/********************************************************************************
** Form generated from reading UI file 'historypage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYPAGE_H
#define UI_HISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_historypage
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *historypage)
    {
        if (historypage->objectName().isEmpty())
            historypage->setObjectName("historypage");
        historypage->resize(800, 600);
        centralwidget = new QWidget(historypage);
        centralwidget->setObjectName("centralwidget");
        historypage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(historypage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        historypage->setMenuBar(menubar);
        statusbar = new QStatusBar(historypage);
        statusbar->setObjectName("statusbar");
        historypage->setStatusBar(statusbar);

        retranslateUi(historypage);

        QMetaObject::connectSlotsByName(historypage);
    } // setupUi

    void retranslateUi(QMainWindow *historypage)
    {
        historypage->setWindowTitle(QCoreApplication::translate("historypage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historypage: public Ui_historypage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYPAGE_H
