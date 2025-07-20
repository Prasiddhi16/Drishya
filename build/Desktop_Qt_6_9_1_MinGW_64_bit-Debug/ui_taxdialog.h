/********************************************************************************
** Form generated from reading UI file 'taxdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAXDIALOG_H
#define UI_TAXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taxDialog
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *no_btn;
    QPushButton *yes_btn;

    void setupUi(QDialog *taxDialog)
    {
        if (taxDialog->objectName().isEmpty())
            taxDialog->setObjectName("taxDialog");
        taxDialog->resize(400, 300);
        taxDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background-color: #131b39\n"
"}"));
        label = new QLabel(taxDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 351, 51));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:white;\n"
"	background-color: transparent;\n"
"	font: 27pt \"Al Bayan\";\n"
"}\n"
""));
        horizontalLayoutWidget = new QWidget(taxDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(17, 239, 371, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        no_btn = new QPushButton(horizontalLayoutWidget);
        no_btn->setObjectName("no_btn");
        no_btn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"color:black;\n"
"}\n"
""));

        horizontalLayout->addWidget(no_btn);

        yes_btn = new QPushButton(horizontalLayoutWidget);
        yes_btn->setObjectName("yes_btn");
        yes_btn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color:black;\n"
"}\n"
""));

        horizontalLayout->addWidget(yes_btn);


        retranslateUi(taxDialog);

        QMetaObject::connectSlotsByName(taxDialog);
    } // setupUi

    void retranslateUi(QDialog *taxDialog)
    {
        taxDialog->setWindowTitle(QCoreApplication::translate("taxDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("taxDialog", "\360\237\222\215Are you married?", nullptr));
        no_btn->setText(QCoreApplication::translate("taxDialog", "No", nullptr));
        yes_btn->setText(QCoreApplication::translate("taxDialog", "Yes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taxDialog: public Ui_taxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAXDIALOG_H
