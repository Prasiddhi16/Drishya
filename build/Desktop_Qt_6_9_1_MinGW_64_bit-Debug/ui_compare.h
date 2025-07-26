/********************************************************************************
** Form generated from reading UI file 'compare.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARE_H
#define UI_COMPARE_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_compare
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QChartView *chartWidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *compare)
    {
        if (compare->objectName().isEmpty())
            compare->setObjectName("compare");
        compare->resize(800, 600);
        centralwidget = new QWidget(compare);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 90, 841, 471));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        chartWidget = new QChartView(verticalLayoutWidget);
        chartWidget->setObjectName("chartWidget");

        verticalLayout_2->addWidget(chartWidget);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 10, 471, 71));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font-size: 24px;\n"
"font-weight: bold;\n"
"color: white;\n"
"margin-bottom: 10px;\n"
"	font:  \"Arial Black\";\n"
"\n"
"}"));
        compare->setCentralWidget(centralwidget);
        menubar = new QMenuBar(compare);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        compare->setMenuBar(menubar);
        statusbar = new QStatusBar(compare);
        statusbar->setObjectName("statusbar");
        compare->setStatusBar(statusbar);

        retranslateUi(compare);

        QMetaObject::connectSlotsByName(compare);
    } // setupUi

    void retranslateUi(QMainWindow *compare)
    {
        compare->setWindowTitle(QCoreApplication::translate("compare", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("compare", "<html><head/><body><p><span style=\" font-size:28pt;\">\342\232\226\357\270\217 Compare: Actual vs Ideal Finance</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class compare: public Ui_compare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARE_H
