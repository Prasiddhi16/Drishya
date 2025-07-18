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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QWidget *widget_2;
    QLineEdit *searchlineedit;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label_2;
    QWidget *Page2;
    QLabel *label_3;
    QWidget *page_4;
    QLabel *label_4;
    QWidget *page_2;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1539, 832);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 1511, 791));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName("widget");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 1351, 171));
        searchlineedit = new QLineEdit(widget_2);
        searchlineedit->setObjectName("searchlineedit");
        searchlineedit->setGeometry(QRect(530, 110, 431, 41));
        searchlineedit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"padding: 10px 12px;\n"
"font-size: 16px;\n"
"border: none;\n"
"border-radius: 6px;\n"
"min-width: 300px;\n"
""));
        toolBox = new QToolBox(widget);
        toolBox->setObjectName("toolBox");
        toolBox->setEnabled(true);
        toolBox->setGeometry(QRect(0, 190, 1511, 581));
        toolBox->setStyleSheet(QString::fromUtf8("color: #2e2e2e;\n"
"font-family: \"Segoe UI\", Tahoma, sans-serif;\n"
"font-size: 17px;\n"
"font-weight: 500;\n"
"background-color: #e3f2fd;   /* Soft blue, not white */\n"
"padding: 12px 16px;\n"
"border-radius: 10px;\n"
"border: 1px solid #90caf9;   /* Light blue border */\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 1443, 373));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(0, 0, 1441, 371));
        label_2->setStyleSheet(QString::fromUtf8("color: #1a1a1a;  /* deeper black text */\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0, x2: 1, y2: 1,\n"
"    stop: 0 #ffffff,\n"
"    stop: 1 #f5f5f5\n"
");  /* modern light gradient background */\n"
"\n"
"font-family: \"Segoe UI\", Tahoma, sans-serif;\n"
"font-size: 16px;\n"
"font-weight: 500;\n"
"\n"
"padding: 14px 18px;\n"
"border-radius: 12px;\n"
"border: 1px solid #bdbdbd;\n"
"\n"
"box-shadow: 0px 2px 6px rgba(0, 0, 0, 0.1); /* subtle shadow effect */\n"
""));
        label_2->setTextFormat(Qt::TextFormat::MarkdownText);
        toolBox->addItem(page, QString::fromUtf8("\360\237\224\220 Account & Login"));
        Page2 = new QWidget();
        Page2->setObjectName("Page2");
        label_3 = new QLabel(Page2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 1441, 371));
        label_3->setStyleSheet(QString::fromUtf8("color: #1a1a1a;  /* deeper black text */\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0, x2: 1, y2: 1,\n"
"    stop: 0 #ffffff,\n"
"    stop: 1 #f5f5f5\n"
");  /* modern light gradient background */\n"
"\n"
"font-family: \"Segoe UI\", Tahoma, sans-serif;\n"
"font-size: 16px;\n"
"font-weight: 500;\n"
"\n"
"padding: 14px 18px;\n"
"border-radius: 12px;\n"
"border: 1px solid #bdbdbd;\n"
"\n"
"box-shadow: 0px 2px 6px rgba(0, 0, 0, 0.1); /* subtle shadow effect */\n"
""));
        toolBox->addItem(Page2, QString::fromUtf8(" \360\237\222\260 Transactions & Records"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_4 = new QLabel(page_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 1441, 371));
        label_4->setStyleSheet(QString::fromUtf8("color: #1a1a1a;  /* deeper black text */\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0, x2: 1, y2: 1,\n"
"    stop: 0 #ffffff,\n"
"    stop: 1 #f5f5f5\n"
");  /* modern light gradient background */\n"
"\n"
"font-family: \"Segoe UI\", Tahoma, sans-serif;\n"
"font-size: 16px;\n"
"font-weight: 500;\n"
"\n"
"padding: 14px 18px;\n"
"border-radius: 12px;\n"
"border: 1px solid #bdbdbd;\n"
"\n"
"box-shadow: 0px 2px 6px rgba(0, 0, 0, 0.1); /* subtle shadow effect */\n"
""));
        toolBox->addItem(page_4, QString::fromUtf8(" \360\237\223\212 Reports & Insights"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 1443, 373));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 1441, 371));
        label_5->setStyleSheet(QString::fromUtf8("color: #1a1a1a;  /* deeper black text */\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0, x2: 1, y2: 1,\n"
"    stop: 0 #ffffff,\n"
"    stop: 1 #f5f5f5\n"
");  /* modern light gradient background */\n"
"\n"
"font-family: \"Segoe UI\", Tahoma, sans-serif;\n"
"font-size: 16px;\n"
"font-weight: 500;\n"
"\n"
"padding: 14px 18px;\n"
"border-radius: 12px;\n"
"border: 1px solid #bdbdbd;\n"
"\n"
"box-shadow: 0px 2px 6px rgba(0, 0, 0, 0.1); /* subtle shadow effect */\n"
""));
        toolBox->addItem(page_2, QString::fromUtf8("\342\232\231\357\270\217 General Settings & Support"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1921, 181));
        label->setStyleSheet(QString::fromUtf8("\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 #FF6A3D,\n"
"                                stop:0.5 #F6E9F0,\n"
"                                stop:1 #3D9EFF);\n"
"\n"
"\n"
"\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    color: #1E1E1E;\n"
"\n"
""));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(540, 120, 361, 51));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchlineedit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Search", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\342\236\244What is Artha Drishya?</p><p>Track your income, expenses, and budgets in one place. Stay in control of your personal finances with simple tools and helpful insights.</p><p>\342\236\244How to Sign Up?</p><p>Tap \342\200\234Sign Up,\342\200\235 enter your email and password, and confirm your details. Verify your email (if needed) to activate your account.</p><p>\342\236\244 How to Log In?</p><p>Enter your registered email and password on the login screen. Tap \342\200\234Login\342\200\235 to access your dashboard.</p><p>\342\236\244Forgot Password?</p><p>....</p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\360\237\224\220 Account & Login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\342\236\244 What is the Record Page?</p><p>This is where you log every income or expense to keep your financial records up to date.</p><p>\342\236\244 Adding a Transaction</p><p>Choose income or expense, fill in amount, category, date, and reviw then tap \342\200\234Add Record&quot;.</p><p>\342\236\244 Editing or Deleting a Transaction</p><p>Go to the Analyze or History page, tap a transaction to edit or delete it using the pencil or trash icon.</p><p>\342\236\244 Managing Accounts</p><p>From Settings &gt; Accounts, you can add your cash, bank, or credit card accounts and assign them when recording transactions</p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(Page2), QCoreApplication::translate("MainWindow", " \360\237\222\260 Transactions & Records", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\342\236\244 What is the Analyze Page?</p><p>View summaries of your income, expenses, and net balance through easy charts and dashboards.</p><p>\342\236\244 Spending Breakdown by Category</p><p>See where your money goes with pie charts and bars showing each category\342\200\231s share (e.g., Food, Rent).</p><p>\342\236\244 Income vs. Expense Trends</p><p>View your financial flow over time \342\200\224 monthly or yearly trends to help understand saving vs. spending.</p><p>\342\236\244 Budgets &amp; Limits</p><p>Set budget limits per category and track your usage. Alerts will notify you if you\342\200\231re close to overspending.</p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", " \360\237\223\212 Reports & Insights", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\342\236\244 Notification Settings</p><p>Control reminders for budgets, bills, and goals under Settings &gt; Notifications.</p><p>\342\236\244 Troubleshooting Tips</p><p>-Charts not updating? Refresh your data.</p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 General Settings & Support", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "                                                                       How can we help you?", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
