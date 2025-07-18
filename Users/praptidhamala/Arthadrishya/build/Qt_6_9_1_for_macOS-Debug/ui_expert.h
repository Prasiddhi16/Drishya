/********************************************************************************
** Form generated from reading UI file 'expert.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERT_H
#define UI_EXPERT_H

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

class Ui_expert
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *InsightBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *chartLayout;
    QPushButton *btnRefresh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *expert)
    {
        if (expert->objectName().isEmpty())
            expert->setObjectName("expert");
        expert->resize(800, 600);
        centralwidget = new QWidget(expert);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 10, 241, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font-size: 24px; \n"
"color: white; \n"
"	font: 24pt \"Menlos\";\n"
"allignment:center;\n"
"}"));
        InsightBox = new QLabel(centralwidget);
        InsightBox->setObjectName("InsightBox");
        InsightBox->setGeometry(QRect(200, 60, 471, 111));
        InsightBox->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: #ffffff; border-radius: 15px; border: 2px solid #cdb4db; font-size: 16px; color: #3c096c; padding: 12px;\n"
"}"));
        InsightBox->setWordWrap(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 180, 571, 311));
        chartLayout = new QVBoxLayout(verticalLayoutWidget);
        chartLayout->setObjectName("chartLayout");
        chartLayout->setContentsMargins(0, 0, 0, 0);
        btnRefresh = new QPushButton(centralwidget);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setGeometry(QRect(290, 510, 251, 51));
        btnRefresh->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: white; color: black; border-radius: 12px; padding: 8px 16px; font-weight: bold;\n"
"	font: 24pt \"Helvetica\";\n"
"}"));
        expert->setCentralWidget(centralwidget);
        menubar = new QMenuBar(expert);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        expert->setMenuBar(menubar);
        statusbar = new QStatusBar(expert);
        statusbar->setObjectName("statusbar");
        expert->setStatusBar(statusbar);

        retranslateUi(expert);

        QMetaObject::connectSlotsByName(expert);
    } // setupUi

    void retranslateUi(QMainWindow *expert)
    {
        expert->setWindowTitle(QCoreApplication::translate("expert", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("expert", "\360\237\222\241EXPERT REVIEW", nullptr));
        InsightBox->setText(QCoreApplication::translate("expert", "\360\237\224\215 Insights will appear here...", nullptr));
        btnRefresh->setText(QCoreApplication::translate("expert", "\360\237\224\204 Refresh Insight", nullptr));
    } // retranslateUi

};

namespace Ui {
    class expert: public Ui_expert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERT_H
