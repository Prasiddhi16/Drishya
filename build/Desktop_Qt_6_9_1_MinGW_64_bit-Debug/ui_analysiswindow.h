/********************************************************************************
** Form generated from reading UI file 'analysiswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISWINDOW_H
#define UI_ANALYSISWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analysisWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QLabel *label;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_weekly;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *expense_label;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *percentage_label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *analysisWindow)
    {
        if (analysisWindow->objectName().isEmpty())
            analysisWindow->setObjectName("analysisWindow");
        analysisWindow->resize(800, 609);
        QPalette palette;
        QBrush brush(QColor(19, 27, 57, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        analysisWindow->setPalette(palette);
        analysisWindow->setStyleSheet(QString::fromUtf8("background-color: #131b39;\n"
"\n"
""));
        centralwidget = new QWidget(analysisWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:#131b39;"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setMinimumSize(QSize(50, 50));
        toolButton->setStyleSheet(QString::fromUtf8("border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        horizontalLayout_2->addWidget(toolButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(3, 100));
        label->setMaximumSize(QSize(16777215, 100));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 27, 57);"));

        horizontalLayout_2->addWidget(label);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame_weekly = new QFrame(centralwidget);
        frame_weekly->setObjectName("frame_weekly");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_weekly->sizePolicy().hasHeightForWidth());
        frame_weekly->setSizePolicy(sizePolicy1);
        frame_weekly->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 255);\n"
"border-radius:50px;l"));
        frame_weekly->setFrameShape(QFrame::Shape::StyledPanel);
        frame_weekly->setFrameShadow(QFrame::Shadow::Raised);
        gridLayoutWidget = new QWidget(frame_weekly);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 20, 421, 257));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(1);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(80, 20, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_3, 8, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 10, 0, 1, 1);

        expense_label = new QLabel(gridLayoutWidget);
        expense_label->setObjectName("expense_label");
        sizePolicy1.setHeightForWidth(expense_label->sizePolicy().hasHeightForWidth());
        expense_label->setSizePolicy(sizePolicy1);
        expense_label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(expense_label, 9, 0, 1, 3, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(90, 30));
        pushButton->setMaximumSize(QSize(0, 0));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 170, 255);\n"
"border-radius:10px"));

        gridLayout_2->addWidget(pushButton, 0, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_6, 13, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        percentage_label = new QLabel(gridLayoutWidget);
        percentage_label->setObjectName("percentage_label");
        sizePolicy1.setHeightForWidth(percentage_label->sizePolicy().hasHeightForWidth());
        percentage_label->setSizePolicy(sizePolicy1);
        percentage_label->setMinimumSize(QSize(10, 0));
        percentage_label->setMaximumSize(QSize(70, 50));
        percentage_label->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 0, 0);\n"
"border-radius:400;"));

        gridLayout_2->addWidget(percentage_label, 13, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 12, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 0, 1, 1);


        verticalLayout_6->addWidget(frame_weekly);


        gridLayout->addLayout(verticalLayout_6, 7, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #bccdb7;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    font-size: 16pt;\n"
"    color: black; /* <-- Text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #b8e6c1;\n"
"    color: black; /* Ensure hover doesn't change text color */\n"
"}"));

        verticalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(40, 10));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #bccdb7;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    font-size: 16pt;\n"
"    color: black; /* <-- Text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #b8e6c1;\n"
"    color: black; /* Ensure hover doesn't change text color */\n"
"}"));

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #bccdb7;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    font-size: 16pt;\n"
"    color: black; /* <-- Text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #b8e6c1;\n"
"    color: black; /* Ensure hover doesn't change text color */\n"
"}"));

        verticalLayout_4->addWidget(pushButton_4);


        gridLayout->addLayout(verticalLayout_4, 7, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(30, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        label_2->setPalette(palette1);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 6, 1, 1, 1);

        analysisWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(analysisWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        analysisWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(analysisWindow);
        statusbar->setObjectName("statusbar");
        analysisWindow->setStatusBar(statusbar);

        retranslateUi(analysisWindow);

        QMetaObject::connectSlotsByName(analysisWindow);
    } // setupUi

    void retranslateUi(QMainWindow *analysisWindow)
    {
        analysisWindow->setWindowTitle(QCoreApplication::translate("analysisWindow", "MainWindow", nullptr));
        toolButton->setText(QCoreApplication::translate("analysisWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("analysisWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt; font-weight:700; color:#ffffff;\">YOUR ANALYTICS</span><span style=\" font-size:48pt; color:#ffffff;\">\360\237\223\210</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; color:#ffffff;\"><br /></span></p></body></html"
                        ">", nullptr));
        label_3->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; color:#000000;\">Your Weekly Expenses</span></p><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\"><br/></span></p></body></html>", nullptr));
        expense_label->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; color:#000000;\">NRP 120.00</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("analysisWindow", "\342\206\227\357\270\217 View Table ", nullptr));
        label_6->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#000000;\">vs last week</span></p></body></html>", nullptr));
        percentage_label->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">^ 12.3%</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("analysisWindow", "Budget Analysis", nullptr));
        pushButton_3->setText(QCoreApplication::translate("analysisWindow", "Weekly Review", nullptr));
        pushButton_4->setText(QCoreApplication::translate("analysisWindow", "Monthly Review", nullptr));
        label_2->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p><span style=\" font-size:22pt; color:#000000;\">Hello,Your_name!</span></p><p><span style=\" font-size:14pt; color:#000000;\">This is what is going on with your finances</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class analysisWindow: public Ui_analysisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISWINDOW_H
