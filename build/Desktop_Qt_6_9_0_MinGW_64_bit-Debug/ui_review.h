/********************************************************************************
** Form generated from reading UI file 'review.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEW_H
#define UI_REVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_review
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnTax;
    QProgressBar *progressExpenseBar;
    QPushButton *btnExpense;
    QLabel *labelExpense;
    QProgressBar *progressSavingsBar;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *labelSavings;
    QPushButton *btnCompare;
    QPushButton *btnExper;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *review)
    {
        if (review->objectName().isEmpty())
            review->setObjectName("review");
        review->resize(1119, 734);
        review->setStyleSheet(QString::fromUtf8("\n"
"background-color: #131b39\n"
""));
        centralwidget = new QWidget(review);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 0, 671, 71));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 900 48pt \"Arial Black\";\n"
"color:White;\n"
"}\n"
""));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-60, 180, 1081, 491));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(62, 0, 0, 0);
        btnTax = new QPushButton(gridLayoutWidget);
        btnTax->setObjectName("btnTax");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/tax/taxation.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnTax->setIcon(icon);
        btnTax->setIconSize(QSize(200, 200));

        gridLayout->addWidget(btnTax, 11, 2, 1, 1);

        progressExpenseBar = new QProgressBar(gridLayoutWidget);
        progressExpenseBar->setObjectName("progressExpenseBar");
        progressExpenseBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid #cfcfcf;\n"
"    border-radius: 8px;\n"
"    text-align: center;\n"
"    height: 20px;\n"
"color:white;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: pink;\n"
"    width: 10px;\n"
"}"));
        progressExpenseBar->setValue(28);

        gridLayout->addWidget(progressExpenseBar, 4, 0, 1, 2);

        btnExpense = new QPushButton(gridLayoutWidget);
        btnExpense->setObjectName("btnExpense");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Expense_tracker.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExpense->setIcon(icon1);
        btnExpense->setIconSize(QSize(200, 200));

        gridLayout->addWidget(btnExpense, 11, 3, 1, 1);

        labelExpense = new QLabel(gridLayoutWidget);
        labelExpense->setObjectName("labelExpense");
        labelExpense->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"\n"
"	color:white;\n"
"alignment:centre;\n"
"	font: 20pt \"Georgia\";\n"
"}\n"
""));

        gridLayout->addWidget(labelExpense, 0, 0, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        progressSavingsBar = new QProgressBar(gridLayoutWidget);
        progressSavingsBar->setObjectName("progressSavingsBar");
        progressSavingsBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid #cfcfcf;\n"
"    border-radius: 8px;\n"
"    text-align: center;\n"
"    height: 20px;\n"
"color:white;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: pink;\n"
"    width: 10px;\n"
"}"));
        progressSavingsBar->setValue(41);

        gridLayout->addWidget(progressSavingsBar, 4, 2, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        labelSavings = new QLabel(gridLayoutWidget);
        labelSavings->setObjectName("labelSavings");
        labelSavings->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:white;\n"
"	\n"
"	font: 20pt \"Georgia\";\n"
"}\n"
""));

        gridLayout->addWidget(labelSavings, 0, 2, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        btnCompare = new QPushButton(gridLayoutWidget);
        btnCompare->setObjectName("btnCompare");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Compare_contrast.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCompare->setIcon(icon2);
        btnCompare->setIconSize(QSize(200, 200));

        gridLayout->addWidget(btnCompare, 11, 0, 1, 1);

        btnExper = new QPushButton(gridLayoutWidget);
        btnExper->setObjectName("btnExper");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/expert_insight .png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExper->setIcon(icon3);
        btnExper->setIconSize(QSize(200, 200));

        gridLayout->addWidget(btnExper, 10, 1, 2, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 155, 115);\n"
"color:white;\n"
"border-radius:15px;"));

        gridLayout->addWidget(pushButton, 5, 1, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(70, 20, 50, 50));
        toolButton->setMinimumSize(QSize(50, 50));
        toolButton->setStyleSheet(QString::fromUtf8("border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));
        review->setCentralWidget(centralwidget);
        menubar = new QMenuBar(review);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1119, 21));
        review->setMenuBar(menubar);
        statusbar = new QStatusBar(review);
        statusbar->setObjectName("statusbar");
        review->setStatusBar(statusbar);

        retranslateUi(review);

        QMetaObject::connectSlotsByName(review);
    } // setupUi

    void retranslateUi(QMainWindow *review)
    {
        review->setWindowTitle(QCoreApplication::translate("review", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("review", "\360\237\223\235REVIEW PAGE", nullptr));
        btnTax->setText(QString());
        btnExpense->setText(QString());
        labelExpense->setText(QCoreApplication::translate("review", "  \360\237\222\265Monthly Expenses:", nullptr));
        labelSavings->setText(QCoreApplication::translate("review", " \360\237\217\246Monthly Saving:", nullptr));
        btnCompare->setText(QString());
        btnExper->setText(QString());
        pushButton->setText(QCoreApplication::translate("review", "View History", nullptr));
        toolButton->setText(QCoreApplication::translate("review", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class review: public Ui_review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H
