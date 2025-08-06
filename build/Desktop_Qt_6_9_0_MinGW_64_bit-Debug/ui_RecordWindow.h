/********************************************************************************
** Form generated from reading UI file 'RecordWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDWINDOW_H
#define UI_RECORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *editIncomeButton;
    QLabel *label_6;
    QLabel *label_5;
    QComboBox *incomeSource;
    QComboBox *incomeCurrency;
    QLineEdit *incomeAmount;
    QLabel *label_4;
    QWidget *tab_2;
    QComboBox *expenseCategory;
    QComboBox *expenseCurrency;
    QPushButton *editExpenseButton;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *expenseAmount;
    QLabel *label_14;
    QLineEdit *referenceNumber;
    QLabel *label_16;
    QLineEdit *review;
    QDateTimeEdit *timestamp;
    QLabel *label_12;
    QPushButton *addRecordButton;
    QLabel *label_2;
    QLabel *label;
    QToolButton *toolButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RecordWindow)
    {
        if (RecordWindow->objectName().isEmpty())
            RecordWindow->setObjectName("RecordWindow");
        RecordWindow->resize(1498, 836);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecordWindow->sizePolicy().hasHeightForWidth());
        RecordWindow->setSizePolicy(sizePolicy);
        RecordWindow->setMinimumSize(QSize(1150, 780));
        RecordWindow->setStyleSheet(QString::fromUtf8("background-color:		#1c2833;\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(RecordWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(0, 900));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 27, 57);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 60, 731, 731));
        widget->setStyleSheet(QString::fromUtf8("background-color: #E0E0E0;\n"
"\n"
"    \n"
""));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 20, 781, 271));
        tabWidget->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"background-color: rgb(214, 208, 222);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        editIncomeButton = new QPushButton(tab);
        editIncomeButton->setObjectName("editIncomeButton");
        editIncomeButton->setGeometry(QRect(260, 190, 231, 41));
        editIncomeButton->setStyleSheet(QString::fromUtf8("   font-size:25px;\n"
"    background-color: white;  \n"
"    color: green;            \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 130, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;\n"
""));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 20, 141, 21));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        incomeSource = new QComboBox(tab);
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->addItem(QString());
        incomeSource->setObjectName("incomeSource");
        incomeSource->setGeometry(QRect(140, 70, 171, 31));
        incomeSource->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
""));
        incomeCurrency = new QComboBox(tab);
        incomeCurrency->addItem(QString());
        incomeCurrency->setObjectName("incomeCurrency");
        incomeCurrency->setGeometry(QRect(140, 130, 181, 31));
        incomeCurrency->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
""));
        incomeAmount = new QLineEdit(tab);
        incomeAmount->setObjectName("incomeAmount");
        incomeAmount->setGeometry(QRect(140, 20, 171, 31));
        incomeAmount->setStyleSheet(QString::fromUtf8("   font-size:16px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 80, 101, 21));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        expenseCategory = new QComboBox(tab_2);
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->addItem(QString());
        expenseCategory->setObjectName("expenseCategory");
        expenseCategory->setGeometry(QRect(120, 70, 161, 31));
        expenseCategory->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}"));
        expenseCurrency = new QComboBox(tab_2);
        expenseCurrency->addItem(QString());
        expenseCurrency->setObjectName("expenseCurrency");
        expenseCurrency->setEnabled(false);
        expenseCurrency->setGeometry(QRect(120, 120, 171, 31));
        expenseCurrency->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
""));
        editExpenseButton = new QPushButton(tab_2);
        editExpenseButton->setObjectName("editExpenseButton");
        editExpenseButton->setGeometry(QRect(250, 190, 231, 41));
        editExpenseButton->setStyleSheet(QString::fromUtf8("   font-size:25px;\n"
"    background-color: white;  \n"
"    color: green;            \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";\n"
""));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 20, 151, 31));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 120, 121, 31));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 60, 121, 41));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;\n"
""));
        expenseAmount = new QLineEdit(tab_2);
        expenseAmount->setObjectName("expenseAmount");
        expenseAmount->setGeometry(QRect(120, 20, 151, 31));
        expenseAmount->setStyleSheet(QString::fromUtf8("\n"
"   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        tabWidget->addTab(tab_2, QString());
        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 310, 231, 21));
        label_14->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;\n"
"   "));
        referenceNumber = new QLineEdit(widget);
        referenceNumber->setObjectName("referenceNumber");
        referenceNumber->setGeometry(QRect(0, 340, 291, 21));
        referenceNumber->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(480, 310, 181, 31));
        label_16->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;"));
        review = new QLineEdit(widget);
        review->setObjectName("review");
        review->setGeometry(QRect(450, 350, 281, 21));
        review->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        timestamp = new QDateTimeEdit(widget);
        timestamp->setObjectName("timestamp");
        timestamp->setEnabled(false);
        timestamp->setGeometry(QRect(300, 430, 201, 21));
        timestamp->setStyleSheet(QString::fromUtf8("    background-color: white;  \n"
"    font-size: 16px;\n"
"    font-family: \"Rancho\";\n"
"    color: black;"));
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(310, 390, 161, 31));
        label_12->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;\n"
""));
        addRecordButton = new QPushButton(widget);
        addRecordButton->setObjectName("addRecordButton");
        addRecordButton->setGeometry(QRect(280, 480, 251, 41));
        addRecordButton->setStyleSheet(QString::fromUtf8("   font-size:30px;\n"
"    background-color:  #B55D60;\n"
"    \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(390, 0, 261, 31));
        label_2->setStyleSheet(QString::fromUtf8("    color:  red;\n"
"    font-weight: bold;\n"
"    font-size: 30px;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(740, 60, 761, 561));
        label->setMinimumSize(QSize(100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/record.png")));
        label->setScaledContents(false);
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(10, 0, 50, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setMinimumSize(QSize(30, 30));
        toolButton->setStyleSheet(QString::fromUtf8("border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));
        RecordWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(RecordWindow);
        statusbar->setObjectName("statusbar");
        RecordWindow->setStatusBar(statusbar);

        retranslateUi(RecordWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RecordWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RecordWindow)
    {
        RecordWindow->setWindowTitle(QCoreApplication::translate("RecordWindow", "MainWindow", nullptr));
        editIncomeButton->setText(QCoreApplication::translate("RecordWindow", "Edit Income", nullptr));
        label_6->setText(QCoreApplication::translate("RecordWindow", "Currency  :", nullptr));
        label_5->setText(QCoreApplication::translate("RecordWindow", " Amount :", nullptr));
        incomeSource->setItemText(0, QCoreApplication::translate("RecordWindow", "Salary", nullptr));
        incomeSource->setItemText(1, QCoreApplication::translate("RecordWindow", "Business ", nullptr));
        incomeSource->setItemText(2, QCoreApplication::translate("RecordWindow", "Interest", nullptr));
        incomeSource->setItemText(3, QCoreApplication::translate("RecordWindow", "Dividends", nullptr));
        incomeSource->setItemText(4, QCoreApplication::translate("RecordWindow", "Retirement Funds", nullptr));
        incomeSource->setItemText(5, QCoreApplication::translate("RecordWindow", "Commisions", nullptr));
        incomeSource->setItemText(6, QCoreApplication::translate("RecordWindow", "Others", nullptr));

        incomeCurrency->setItemText(0, QCoreApplication::translate("RecordWindow", "NPR", nullptr));

        incomeAmount->setText(QString());
        label_4->setText(QCoreApplication::translate("RecordWindow", "Sources :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RecordWindow", "Income", nullptr));
        expenseCategory->setItemText(0, QCoreApplication::translate("RecordWindow", "Food", nullptr));
        expenseCategory->setItemText(1, QCoreApplication::translate("RecordWindow", "Shopping", nullptr));
        expenseCategory->setItemText(2, QCoreApplication::translate("RecordWindow", "Housing", nullptr));
        expenseCategory->setItemText(3, QCoreApplication::translate("RecordWindow", "Entertainment", nullptr));
        expenseCategory->setItemText(4, QCoreApplication::translate("RecordWindow", "Transport", nullptr));
        expenseCategory->setItemText(5, QCoreApplication::translate("RecordWindow", "Electronics", nullptr));
        expenseCategory->setItemText(6, QCoreApplication::translate("RecordWindow", "Investment", nullptr));
        expenseCategory->setItemText(7, QCoreApplication::translate("RecordWindow", "Others", nullptr));

        expenseCurrency->setItemText(0, QCoreApplication::translate("RecordWindow", "NPR", nullptr));

        editExpenseButton->setText(QCoreApplication::translate("RecordWindow", "Edit Expenses", nullptr));
        label_8->setText(QCoreApplication::translate("RecordWindow", "Amount   :", nullptr));
        label_9->setText(QCoreApplication::translate("RecordWindow", " Currency  :", nullptr));
        label_7->setText(QCoreApplication::translate("RecordWindow", " Category  :", nullptr));
        expenseAmount->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RecordWindow", "Expenses", nullptr));
        label_14->setText(QCoreApplication::translate("RecordWindow", "ID/Bill No:", nullptr));
        referenceNumber->setText(QString());
        label_16->setText(QCoreApplication::translate("RecordWindow", "Review  :", nullptr));
        review->setText(QString());
        label_12->setText(QCoreApplication::translate("RecordWindow", "Timestamp", nullptr));
        addRecordButton->setText(QCoreApplication::translate("RecordWindow", "Add Record", nullptr));
        label_2->setText(QCoreApplication::translate("RecordWindow", "FINANCE RECORD", nullptr));
        label->setText(QString());
        toolButton->setText(QCoreApplication::translate("RecordWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordWindow: public Ui_RecordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDWINDOW_H
