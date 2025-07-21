/********************************************************************************
** Form generated from reading UI file 'Help.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label_2;
    QWidget *Page2;
    QLabel *label_3;
    QWidget *page_4;
    QLabel *label_4;
    QWidget *page_2;
    QLabel *label_5;

    void setupUi(QMainWindow *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName("Help");
        Help->resize(1539, 832);
        QPalette palette;
        QBrush brush(QColor(19, 27, 57, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        Help->setPalette(palette);
        centralwidget = new QWidget(Help);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1541, 841));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName("widget");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, -40, 1551, 161));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(-120, 40, 1201, 101));
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
        toolBox = new QToolBox(widget);
        toolBox->setObjectName("toolBox");
        toolBox->setEnabled(true);
        toolBox->setGeometry(QRect(10, 120, 1081, 501));
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
        page->setGeometry(QRect(0, 0, 1013, 301));
        page->setMinimumSize(QSize(200, 200));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(0, 0, 1181, 301));
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
        Page2->setGeometry(QRect(0, 0, 1013, 301));
        label_3 = new QLabel(Page2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 1181, 301));
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
        page_4->setGeometry(QRect(0, 0, 1013, 301));
        label_4 = new QLabel(page_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 1181, 301));
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
        page_2->setGeometry(QRect(0, 0, 1013, 301));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 1191, 301));
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

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        Help->setCentralWidget(centralwidget);

        retranslateUi(Help);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QMainWindow *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Help", "                                                                       How can we help you?", nullptr));
        label_2->setText(QCoreApplication::translate("Help", "<html><head/><body><p>\342\236\244What is Artha Drishya?</p><p>Track your income, expenses, and budgets in one place. Stay in control of your personal finances with simple tools and insights.</p><p>\342\236\244 How to Log In?</p><p>Enter your registered email and password on the login screen. Tap \342\200\234Login\342\200\235 to access your dashboard.</p><p>\342\236\244Forgot Password?</p><p>Enter your pet name,date of birth or email to access your old account</p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Help", "\360\237\224\220 Account & Login", nullptr));
        label_3->setText(QCoreApplication::translate("Help", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\236\244 What is the Record Page?</span></p><p><span style=\" font-size:12pt;\">This is where you log every income or expense to keep your financial records up to date.</span></p><p><span style=\" font-size:12pt;\">\342\236\244 Adding a Transaction</span></p><p><span style=\" font-size:12pt;\">Choose income or expense, fill in amount, category, date, and reviw then tap \342\200\234Add Record&quot;.</span></p><p><span style=\" font-size:12pt;\">\342\236\244 Editing the income or expenses field</span></p><p><span style=\" font-size:12pt;\">Go to the Edit income or Edit expenses section to edit the previous values </span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p><p><span style=\" font-s"
                        "ize:12pt;\"><br/></span></p><p><span style=\" font-size:12pt;\"><br/></span></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(Page2), QCoreApplication::translate("Help", " \360\237\222\260 Transactions & Records", nullptr));
        label_4->setText(QCoreApplication::translate("Help", "<html><head/><body><p>\342\236\244 What is the Analyze Page?</p><p>View summaries of your income, expenses, and net balance through easy charts and dashboards.</p><p>\342\236\244 Spending Breakdown by Category</p><p>See where your money goes with pie charts and bars showing each category\342\200\231s share (e.g., Food, Rent).</p><p>\342\236\244 Income vs. Expense Trends</p><p>View your financial flow over time \342\200\224 monthly or yearly trends to help understand saving vs. spending.</p><p>\342\236\244 Budgets &amp; Limits</p><p>Set budget limits per category and track your usage. </p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("Help", " \360\237\223\212 Reports & Insights", nullptr));
        label_5->setText(QCoreApplication::translate("Help", "<html><head/><body><p>\342\236\244 Notification Settings</p><p>Control reminders for budgets, bills, and goals under Settings &gt; Notifications.</p><p>\342\236\244 Troubleshooting Tips</p><p>-Charts not updating? Refresh your data.</p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Help", "\342\232\231\357\270\217 General Settings & Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
