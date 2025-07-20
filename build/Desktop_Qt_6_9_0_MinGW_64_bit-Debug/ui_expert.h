/********************************************************************************
** Form generated from reading UI file 'expert.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_expert
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *InsightBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *chartLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *expert)
    {
        if (expert->objectName().isEmpty())
            expert->setObjectName("expert");
        expert->resize(889, 600);
        centralwidget = new QWidget(expert);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(60, 20, 1161, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(88, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font-size: 24px; \n"
"color: white; \n"
"	font: 24pt \"Menlos\";\n"
"allignment:center;\n"
"}"));

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        InsightBox = new QLabel(verticalLayoutWidget_2);
        InsightBox->setObjectName("InsightBox");
        InsightBox->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: #ffffff; border-radius: 15px; border: 2px solid #cdb4db; font-size: 16px; color: #3c096c; padding: 12px;\n"
"}"));
        InsightBox->setWordWrap(true);

        verticalLayout->addWidget(InsightBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");
        chartLayout->setContentsMargins(6, -1, -1, -1);

        verticalLayout->addLayout(chartLayout);

        expert->setCentralWidget(centralwidget);
        menubar = new QMenuBar(expert);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 889, 17));
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
    } // retranslateUi

};

namespace Ui {
    class expert: public Ui_expert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERT_H
