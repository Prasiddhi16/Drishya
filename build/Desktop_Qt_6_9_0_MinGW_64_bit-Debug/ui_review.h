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
    QProgressBar *progressBar_2;
    QPushButton *btnExpense;
    QLabel *label_2;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QPushButton *btnCompare;
    QPushButton *btnExper;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *review)
    {
        if (review->objectName().isEmpty())
            review->setObjectName("review");
        review->resize(1198, 734);
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
        gridLayoutWidget->setGeometry(QRect(0, 100, 1100, 551));
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

        progressBar_2 = new QProgressBar(gridLayoutWidget);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
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
        progressBar_2->setValue(28);

        gridLayout->addWidget(progressBar_2, 4, 0, 1, 2);

        btnExpense = new QPushButton(gridLayoutWidget);
        btnExpense->setObjectName("btnExpense");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Expense_tracker.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExpense->setIcon(icon1);
        btnExpense->setIconSize(QSize(200, 200));

        gridLayout->addWidget(btnExpense, 11, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"\n"
"	color:white;\n"
"alignment:centre;\n"
"	font: 20pt \"Georgia\";\n"
"}\n"
""));

        gridLayout->addWidget(label_2, 0, 0, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
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
        progressBar->setValue(41);

        gridLayout->addWidget(progressBar, 4, 2, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:white;\n"
"	\n"
"	font: 20pt \"Georgia\";\n"
"}\n"
""));

        gridLayout->addWidget(label_3, 0, 2, 1, 2, Qt::AlignmentFlag::AlignHCenter);

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

        review->setCentralWidget(centralwidget);
        menubar = new QMenuBar(review);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1198, 17));
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
        label_2->setText(QCoreApplication::translate("review", "  \360\237\222\265Monthly Expenses:", nullptr));
        label_3->setText(QCoreApplication::translate("review", " \360\237\217\246Monthly Saving:", nullptr));
        btnCompare->setText(QString());
        btnExper->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class review: public Ui_review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H
