/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
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
    QFrame *line;
    QLabel *label_2;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1498, 836);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:		#1c2833"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 40, 731, 781));
        widget->setStyleSheet(QString::fromUtf8("background-color: #E0E0E0;\n"
"\n"
"    \n"
""));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 10, 781, 331));
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(214, 208, 222);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        editIncomeButton = new QPushButton(tab);
        editIncomeButton->setObjectName("editIncomeButton");
        editIncomeButton->setGeometry(QRect(260, 240, 231, 51));
        editIncomeButton->setStyleSheet(QString::fromUtf8("   font-size:30px;\n"
"    background-color: white;  \n"
"    color: green;            \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 150, 121, 31));
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
        incomeSource->setGeometry(QRect(190, 80, 171, 41));
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
        incomeCurrency->setGeometry(QRect(210, 140, 181, 51));
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
        incomeAmount->setGeometry(QRect(210, 30, 171, 41));
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
        expenseCategory->setGeometry(QRect(190, 80, 141, 41));
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
        expenseCurrency->setGeometry(QRect(190, 140, 151, 41));
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
        editExpenseButton->setGeometry(QRect(180, 200, 231, 51));
        editExpenseButton->setStyleSheet(QString::fromUtf8("   font-size:30px;\n"
"    background-color: white;  \n"
"    color: green;            \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 20, 151, 31));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 150, 171, 31));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 80, 131, 41));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;\n"
""));
        expenseAmount = new QLineEdit(tab_2);
        expenseAmount->setObjectName("expenseAmount");
        expenseAmount->setGeometry(QRect(160, 30, 141, 31));
        expenseAmount->setStyleSheet(QString::fromUtf8("\n"
"   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        tabWidget->addTab(tab_2, QString());
        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 370, 231, 51));
        label_14->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;\n"
"   "));
        referenceNumber = new QLineEdit(widget);
        referenceNumber->setObjectName("referenceNumber");
        referenceNumber->setGeometry(QRect(10, 420, 291, 61));
        referenceNumber->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(500, 370, 181, 41));
        label_16->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;"));
        review = new QLineEdit(widget);
        review->setObjectName("review");
        review->setGeometry(QRect(420, 410, 281, 61));
        review->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        timestamp = new QDateTimeEdit(widget);
        timestamp->setObjectName("timestamp");
        timestamp->setEnabled(false);
        timestamp->setGeometry(QRect(280, 520, 201, 51));
        timestamp->setStyleSheet(QString::fromUtf8("    background-color: white;  \n"
"    font-size: 16px;\n"
"    font-family: \"Rancho\";\n"
"    color: black;"));
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(310, 490, 161, 21));
        label_12->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;\n"
""));
        addRecordButton = new QPushButton(widget);
        addRecordButton->setObjectName("addRecordButton");
        addRecordButton->setGeometry(QRect(260, 630, 251, 71));
        addRecordButton->setStyleSheet(QString::fromUtf8("   font-size:30px;\n"
"    background-color:  #B55D60;\n"
"    \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(-70, 40, 1601, 2));
        line->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #00FFFF;\n"
"    min-height: 2px;  /* Line thickness */\n"
"    max-height: 2px;\n"
"    border: none;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 0, 261, 41));
        label_2->setStyleSheet(QString::fromUtf8("    color:  red;\n"
"    font-weight: bold;\n"
"    font-size: 30px;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(730, 170, 771, 451));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/record.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        editIncomeButton->setText(QCoreApplication::translate("MainWindow", "Edit income", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Currency  :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " Amount :", nullptr));
        incomeSource->setItemText(0, QCoreApplication::translate("MainWindow", "Salary", nullptr));
        incomeSource->setItemText(1, QCoreApplication::translate("MainWindow", "Business ", nullptr));
        incomeSource->setItemText(2, QCoreApplication::translate("MainWindow", "Interest", nullptr));
        incomeSource->setItemText(3, QCoreApplication::translate("MainWindow", "Dividends", nullptr));
        incomeSource->setItemText(4, QCoreApplication::translate("MainWindow", "Retirement Funds", nullptr));
        incomeSource->setItemText(5, QCoreApplication::translate("MainWindow", "Commisions", nullptr));
        incomeSource->setItemText(6, QCoreApplication::translate("MainWindow", "Others", nullptr));

        incomeCurrency->setItemText(0, QCoreApplication::translate("MainWindow", "NPR", nullptr));

        incomeAmount->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Sources :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Income", nullptr));
        expenseCategory->setItemText(0, QCoreApplication::translate("MainWindow", "Food", nullptr));
        expenseCategory->setItemText(1, QCoreApplication::translate("MainWindow", "Shopping", nullptr));
        expenseCategory->setItemText(2, QCoreApplication::translate("MainWindow", "Housing", nullptr));
        expenseCategory->setItemText(3, QCoreApplication::translate("MainWindow", "Entertainment", nullptr));
        expenseCategory->setItemText(4, QCoreApplication::translate("MainWindow", "Transport", nullptr));
        expenseCategory->setItemText(5, QCoreApplication::translate("MainWindow", "Electronics", nullptr));
        expenseCategory->setItemText(6, QCoreApplication::translate("MainWindow", "Investment", nullptr));
        expenseCategory->setItemText(7, QCoreApplication::translate("MainWindow", "Others", nullptr));

        expenseCurrency->setItemText(0, QCoreApplication::translate("MainWindow", "NPR", nullptr));

        editExpenseButton->setText(QCoreApplication::translate("MainWindow", "Edit expenses", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Amount   :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Currency   :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Category    :", nullptr));
        expenseAmount->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ID/Reference No:", nullptr));
        referenceNumber->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Review  :", nullptr));
        review->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Timestamp", nullptr));
        addRecordButton->setText(QCoreApplication::translate("MainWindow", "Add record", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FINANCE RECORD", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
