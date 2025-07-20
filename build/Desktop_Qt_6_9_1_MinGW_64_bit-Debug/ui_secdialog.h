/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secDialog
{
public:
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *eno;
    QPushButton *eyes;

    void setupUi(QDialog *secDialog)
    {
        if (secDialog->objectName().isEmpty())
            secDialog->setObjectName("secDialog");
        secDialog->resize(509, 300);
        secDialog->setStyleSheet(QString::fromUtf8("background-color: #131b39;"));
        label = new QLabel(secDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 521, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 900 20pt \"Arial Black\";"));
        radioButton = new QRadioButton(secDialog);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(150, 100, 100, 20));
        radioButton->setStyleSheet(QString::fromUtf8("color:white;"));
        radioButton_2 = new QRadioButton(secDialog);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(150, 140, 121, 20));
        radioButton_2->setStyleSheet(QString::fromUtf8("color:white;"));
        radioButton_3 = new QRadioButton(secDialog);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(150, 180, 100, 20));
        radioButton_3->setStyleSheet(QString::fromUtf8("color:white;"));
        horizontalLayoutWidget = new QWidget(secDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(50, 250, 361, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        eno = new QPushButton(horizontalLayoutWidget);
        eno->setObjectName("eno");
        eno->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        horizontalLayout->addWidget(eno);

        eyes = new QPushButton(horizontalLayoutWidget);
        eyes->setObjectName("eyes");
        eyes->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        horizontalLayout->addWidget(eyes);


        retranslateUi(secDialog);

        QMetaObject::connectSlotsByName(secDialog);
    } // setupUi

    void retranslateUi(QDialog *secDialog)
    {
        secDialog->setWindowTitle(QCoreApplication::translate("secDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("secDialog", "What is your Employment Status?", nullptr));
        radioButton->setText(QCoreApplication::translate("secDialog", "Employed", nullptr));
        radioButton_2->setText(QCoreApplication::translate("secDialog", "Self-Employed", nullptr));
        radioButton_3->setText(QCoreApplication::translate("secDialog", "Unemployed", nullptr));
        eno->setText(QCoreApplication::translate("secDialog", "Cancel", nullptr));
        eyes->setText(QCoreApplication::translate("secDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secDialog: public Ui_secDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
