/********************************************************************************
** Form generated from reading UI file 'analysiswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISWINDOW_H
#define UI_ANALYSISWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analysisWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *analysisWindow)
    {
        if (analysisWindow->objectName().isEmpty())
            analysisWindow->setObjectName("analysisWindow");
        analysisWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(197, 193, 255, 255));
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
        analysisWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(205, 171, 255);\n"
"background-color: rgb(197, 193, 255);"));
        centralwidget = new QWidget(analysisWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridWidget = new QWidget(frame);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setGeometry(QRect(20, 20, 361, 241));
        gridWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 219, 255);\n"
"border-radius:30px;"));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        label_6 = new QLabel(gridWidget);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_6, 19, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 10, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 8, 1, 1, 1);

        label_5 = new QLabel(gridWidget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(10, 0));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 0, 0);\n"
"border-radius:90px;"));

        gridLayout_2->addWidget(label_5, 19, 1, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        label_4 = new QLabel(gridWidget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 219, 255);"));

        gridLayout_2->addWidget(label_4, 3, 1, 1, 2);

        label_3 = new QLabel(gridWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 219, 255);"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 3, Qt::AlignmentFlag::AlignBottom);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 20, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 21, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 11, 1, 1, 1);

        pushButton = new QPushButton(gridWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(90, 20));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 170, 255);\n"
"border-radius:20px"));

        gridLayout_2->addWidget(pushButton, 5, 1, 1, 2, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_6->addWidget(frame);


        gridLayout->addLayout(verticalLayout_6, 2, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
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


        gridLayout->addLayout(verticalLayout_4, 2, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");

        gridLayout->addLayout(gridLayout_3, 2, 0, 1, 1);

        analysisWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(analysisWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
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
        label_6->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#000000;\">vs last week</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">^ 12.3%</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; color:#000000;\">NRP 120.00</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#000000;\">Your Weekly Expenses</span></p><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\"><br/></span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("analysisWindow", "~", nullptr));
        pushButton_2->setText(QCoreApplication::translate("analysisWindow", "Budget Analysis", nullptr));
        pushButton_3->setText(QCoreApplication::translate("analysisWindow", "Weekly Review", nullptr));
        pushButton_4->setText(QCoreApplication::translate("analysisWindow", "Monthly Review", nullptr));
        label->setText(QCoreApplication::translate("analysisWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt; font-weight:700; color:#000000;\">YOUR ANALYTICS</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\"><br /></span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("analysisWindow", "<html><head/><body><p><span style=\" font-size:22pt; color:#000000;\">Hello,Your_name!</span></p><p><span style=\" font-size:14pt; color:#000000;\">This is what is going on with your finances</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class analysisWindow: public Ui_analysisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISWINDOW_H
