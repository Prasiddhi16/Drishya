/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *statusComboBox;
    QLabel *label_16;
    QFrame *line;
    QLabel *label_15;
    QLineEdit *ReferenceTextEdit;
    QLineEdit *reviewTextEdit;
    QWidget *widget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *incomeSouceComboBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *expensesCategoryComboBox;
    QLineEdit *incomeAmountLineEdit;
    QLineEdit *expensesAmountLineEdit;
    QComboBox *currencyComboBox;
    QComboBox *currencyComboBox_2;
    QLabel *label_10;
    QComboBox *classificationComboBox;
    QLabel *label_11;
    QLabel *label_12;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *identifiersLineEdit;
    QLabel *label_14;
    QLabel *label_2;
    QLabel *label_13;
    QPushButton *addRecordButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1505, 751);
        MainWindow->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f5f7fa, stop:1 #c3cfe2);\n"
"/* Light blue gradient */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        statusComboBox = new QComboBox(centralwidget);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");
        statusComboBox->setGeometry(QRect(960, 540, 281, 41));
        statusComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 18px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(700, 590, 181, 41));
        label_16->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(-60, 50, 1601, 2));
        line->setStyleSheet(QString::fromUtf8("\n"
"    background-color: black;\n"
"    min-height: 2px;  /* Line thickness */\n"
"    max-height: 2px;\n"
"    border: none;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(700, 540, 171, 31));
        label_15->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;"));
        ReferenceTextEdit = new QLineEdit(centralwidget);
        ReferenceTextEdit->setObjectName("ReferenceTextEdit");
        ReferenceTextEdit->setGeometry(QRect(960, 470, 281, 61));
        ReferenceTextEdit->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        reviewTextEdit = new QLineEdit(centralwidget);
        reviewTextEdit->setObjectName("reviewTextEdit");
        reviewTextEdit->setGeometry(QRect(960, 590, 291, 61));
        reviewTextEdit->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 60, 691, 751));
        widget->setStyleSheet(QString::fromUtf8("background-color: lightyellow;\n"
"    \n"
""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 131, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: blue;\n"
"font-weight: bold; "));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 20, 171, 51));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: blue;\n"
"font-weight: bold; \n"
""));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 101, 21));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black\n"
""));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 160, 141, 21));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 210, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;\n"
""));
        incomeSouceComboBox = new QComboBox(widget);
        incomeSouceComboBox->addItem(QString());
        incomeSouceComboBox->addItem(QString());
        incomeSouceComboBox->addItem(QString());
        incomeSouceComboBox->addItem(QString());
        incomeSouceComboBox->setObjectName("incomeSouceComboBox");
        incomeSouceComboBox->setGeometry(QRect(110, 100, 131, 41));
        incomeSouceComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
""));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 90, 131, 41));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;\n"
""));
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(380, 150, 181, 31));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(380, 210, 171, 31));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-family: \"Rancho\";\n"
"color: black;"));
        expensesCategoryComboBox = new QComboBox(widget);
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->addItem(QString());
        expensesCategoryComboBox->setObjectName("expensesCategoryComboBox");
        expensesCategoryComboBox->setGeometry(QRect(530, 100, 141, 41));
        expensesCategoryComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}"));
        incomeAmountLineEdit = new QLineEdit(widget);
        incomeAmountLineEdit->setObjectName("incomeAmountLineEdit");
        incomeAmountLineEdit->setGeometry(QRect(110, 160, 141, 31));
        incomeAmountLineEdit->setStyleSheet(QString::fromUtf8("   font-size:16px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        expensesAmountLineEdit = new QLineEdit(widget);
        expensesAmountLineEdit->setObjectName("expensesAmountLineEdit");
        expensesAmountLineEdit->setGeometry(QRect(530, 150, 141, 31));
        expensesAmountLineEdit->setStyleSheet(QString::fromUtf8("\n"
"   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        currencyComboBox = new QComboBox(widget);
        currencyComboBox->addItem(QString());
        currencyComboBox->setObjectName("currencyComboBox");
        currencyComboBox->setGeometry(QRect(110, 210, 151, 41));
        currencyComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
""));
        currencyComboBox_2 = new QComboBox(widget);
        currencyComboBox_2->addItem(QString());
        currencyComboBox_2->setObjectName("currencyComboBox_2");
        currencyComboBox_2->setEnabled(false);
        currencyComboBox_2->setGeometry(QRect(530, 200, 151, 41));
        currencyComboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
""));
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 300, 221, 91));
        label_10->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-size: 30px;\n"
"color:black;"));
        classificationComboBox = new QComboBox(widget);
        classificationComboBox->addItem(QString());
        classificationComboBox->addItem(QString());
        classificationComboBox->addItem(QString());
        classificationComboBox->addItem(QString());
        classificationComboBox->addItem(QString());
        classificationComboBox->setObjectName("classificationComboBox");
        classificationComboBox->setGeometry(QRect(20, 380, 231, 51));
        classificationComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Rancho\";\n"
"    font-size: 18px;\n"
"    color: black;\n"
"    background: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d0d0d0;\n"
"}"));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(420, 320, 181, 51));
        label_11->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-size: 30px;\n"
"color:black;"));
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(210, 450, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-size: 30px;\n"
"color:black;"));
        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(190, 510, 201, 51));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("    background-color: white;  \n"
"    font-size: 16px;\n"
"    font-family: \"Rancho\";\n"
"    color: black;"));
        identifiersLineEdit = new QLineEdit(widget);
        identifiersLineEdit->setObjectName("identifiersLineEdit");
        identifiersLineEdit->setGeometry(QRect(420, 380, 241, 51));
        identifiersLineEdit->setStyleSheet(QString::fromUtf8("   font-size:18px;\n"
"    background-color: white;  \n"
"    color: black;            \n"
"    border: 1px solid #CCCCCC;\n"
""));
        label->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        incomeSouceComboBox->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        expensesCategoryComboBox->raise();
        incomeAmountLineEdit->raise();
        expensesAmountLineEdit->raise();
        currencyComboBox->raise();
        label_10->raise();
        classificationComboBox->raise();
        label_11->raise();
        label_12->raise();
        dateTimeEdit->raise();
        identifiersLineEdit->raise();
        currencyComboBox_2->raise();
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(700, 470, 231, 51));
        label_14->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-family: \"Rancho\";\n"
"color: red;\n"
"   "));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 0, 351, 41));
        label_2->setStyleSheet(QString::fromUtf8("    color: red;\n"
"    font-weight: bold;\n"
"    font-size: 40px;\n"
""));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(690, 60, 841, 401));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/record.png")));
        label_13->setScaledContents(true);
        addRecordButton = new QPushButton(centralwidget);
        addRecordButton->setObjectName("addRecordButton");
        addRecordButton->setGeometry(QRect(590, 690, 251, 71));
        addRecordButton->setStyleSheet(QString::fromUtf8("   font-size:30px;\n"
"    background-color: white;  \n"
"    color: green;            \n"
"    border: 1px solid #CCCCCC;\n"
"    font-family: \"Consolas\";"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Pending", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Draft", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Queued", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Review  :", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        ReferenceTextEdit->setText(QString());
        reviewTextEdit->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "INCOME", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "EXPENSES", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sources :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " Amount :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Currency  :", nullptr));
        incomeSouceComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Bonus", nullptr));
        incomeSouceComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Investments", nullptr));
        incomeSouceComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Other", nullptr));
        incomeSouceComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Salary", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Category    :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Amount   :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Currency   :", nullptr));
        expensesCategoryComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Groceries", nullptr));
        expensesCategoryComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Rent", nullptr));
        expensesCategoryComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Utilities", nullptr));
        expensesCategoryComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Transportation", nullptr));
        expensesCategoryComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Entertainment", nullptr));
        expensesCategoryComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Other", nullptr));

        incomeAmountLineEdit->setText(QString());
        expensesAmountLineEdit->setText(QString());
        currencyComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "NPR", nullptr));

        currencyComboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "NPR", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "Classification", nullptr));
        classificationComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Saving goal", nullptr));
        classificationComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Income", nullptr));
        classificationComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        classificationComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Transfer", nullptr));
        classificationComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Other", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Identifiers", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Timestamp", nullptr));
        identifiersLineEdit->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "ID/Reference No:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FINANCE RECORD", nullptr));
        label_13->setText(QString());
        addRecordButton->setText(QCoreApplication::translate("MainWindow", "Add record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
