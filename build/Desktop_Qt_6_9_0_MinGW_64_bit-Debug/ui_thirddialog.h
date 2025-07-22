/********************************************************************************
** Form generated from reading UI file 'thirddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDDIALOG_H
#define UI_THIRDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thirdDialog
{
public:
    QLabel *label;
    QRadioButton *rr;
    QRadioButton *rnr;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *rno;
    QPushButton *ryes;

    void setupUi(QDialog *thirdDialog)
    {
        if (thirdDialog->objectName().isEmpty())
            thirdDialog->setObjectName("thirdDialog");
        thirdDialog->resize(493, 300);
        thirdDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background-color:#131b39;\n"
"}"));
        label = new QLabel(thirdDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 661, 51));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:white;\n"
"	font: 900 22pt \"Arial Black\";\n"
"}"));
        rr = new QRadioButton(thirdDialog);
        rr->setObjectName("rr");
        rr->setGeometry(QRect(170, 120, 100, 20));
        rr->setStyleSheet(QString::fromUtf8("color:white;\n"
"\n"
"font: 13pt \"Segoe UI\";"));
        rnr = new QRadioButton(thirdDialog);
        rnr->setObjectName("rnr");
        rnr->setGeometry(QRect(170, 180, 171, 20));
        rnr->setStyleSheet(QString::fromUtf8("color:white;\n"
"\n"
"font: 13pt \"Segoe UI\";"));
        horizontalLayoutWidget = new QWidget(thirdDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 260, 381, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rno = new QPushButton(horizontalLayoutWidget);
        rno->setObjectName("rno");
        rno->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        horizontalLayout->addWidget(rno);

        ryes = new QPushButton(horizontalLayoutWidget);
        ryes->setObjectName("ryes");
        ryes->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        horizontalLayout->addWidget(ryes);


        retranslateUi(thirdDialog);

        QMetaObject::connectSlotsByName(thirdDialog);
    } // setupUi

    void retranslateUi(QDialog *thirdDialog)
    {
        thirdDialog->setWindowTitle(QCoreApplication::translate("thirdDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("thirdDialog", " What is your Residential Status?", nullptr));
        rr->setText(QCoreApplication::translate("thirdDialog", "Resident", nullptr));
        rnr->setText(QCoreApplication::translate("thirdDialog", "Non-Resisdent", nullptr));
        rno->setText(QCoreApplication::translate("thirdDialog", "Cancel", nullptr));
        ryes->setText(QCoreApplication::translate("thirdDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thirdDialog: public Ui_thirdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDDIALOG_H
