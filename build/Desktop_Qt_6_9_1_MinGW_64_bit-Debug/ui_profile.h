/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profile
{
public:
    QGridLayout *gridLayout_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *hello;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_1;
    QSpacerItem *horizontalSpacer;
    QToolButton *about;
    QLabel *about_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_2;
    QToolButton *edit;
    QLabel *edit_2;
    QGridLayout *gridLayout_6;
    QToolButton *privacy;
    QLabel *privacy_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_5;
    QLabel *label_28;
    QToolButton *report;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QToolButton *toolButton_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_2;
    QGridLayout *gridLayout_8;
    QLabel *aboutuser;
    QLabel *emailuser;
    QLabel *label_14;
    QGridLayout *gridLayout_12;
    QLabel *label_26;
    QToolButton *backButton_1;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_20;
    QLabel *dobuser;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_3;
    QGridLayout *gridLayout_9;
    QFormLayout *formLayout_2;
    QLabel *label_17;
    QToolButton *backButton_2;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *current_pass;
    QLabel *label_11;
    QLineEdit *new_pass;
    QLabel *label_12;
    QLineEdit *confirm_pass;
    QPushButton *saveChanges;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_13;
    QLineEdit *user;
    QLabel *label_4;
    QWidget *page_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_10;
    QToolButton *backButton_3;
    QLabel *label_5;
    QLabel *label;
    QWidget *page_5;
    QPlainTextEdit *reviewbox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_11;
    QToolButton *backButton_4;
    QLabel *label_8;
    QPushButton *revbutton;

    void setupUi(QDialog *profile)
    {
        if (profile->objectName().isEmpty())
            profile->setObjectName("profile");
        profile->resize(403, 452);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(profile->sizePolicy().hasHeightForWidth());
        profile->setSizePolicy(sizePolicy);
        profile->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gridLayout_7 = new QGridLayout(profile);
        gridLayout_7->setObjectName("gridLayout_7");
        widget = new QWidget(profile);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI\";\n"
"background-color: rgb(223, 255, 211);\n"
"radius:6px;\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setMinimumSize(QSize(0, 0));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        hello = new QLabel(page);
        hello->setObjectName("hello");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hello->sizePolicy().hasHeightForWidth());
        hello->setSizePolicy(sizePolicy2);
        hello->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"qproperty-alignment: AlignCenter;"));

        verticalLayout_3->addWidget(hello);


        verticalLayout->addLayout(verticalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        toolButton_1 = new QToolButton(page);
        toolButton_1->setObjectName("toolButton_1");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy3);
        toolButton_1->setMinimumSize(QSize(0, 40));
        toolButton_1->setMaximumSize(QSize(40, 40));
        toolButton_1->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_2->addWidget(toolButton_1, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        about = new QToolButton(page);
        about->setObjectName("about");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy4);
        about->setMinimumSize(QSize(0, 0));
        about->setMaximumSize(QSize(16777215, 16777215));
        about->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_2->addWidget(about, 0, 3, 1, 1);

        about_2 = new QLabel(page);
        about_2->setObjectName("about_2");

        gridLayout_2->addWidget(about_2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        toolButton_2 = new QToolButton(page);
        toolButton_2->setObjectName("toolButton_2");
        sizePolicy3.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy3);
        toolButton_2->setMinimumSize(QSize(40, 40));
        toolButton_2->setMaximumSize(QSize(40, 40));
        toolButton_2->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_4->addWidget(toolButton_2, 0, 0, 1, 1);

        edit = new QToolButton(page);
        edit->setObjectName("edit");
        edit->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_4->addWidget(edit, 0, 3, 1, 1);

        edit_2 = new QLabel(page);
        edit_2->setObjectName("edit_2");

        gridLayout_4->addWidget(edit_2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        privacy = new QToolButton(page);
        privacy->setObjectName("privacy");
        privacy->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    \n"
""));

        gridLayout_6->addWidget(privacy, 0, 3, 1, 1);

        privacy_2 = new QLabel(page);
        privacy_2->setObjectName("privacy_2");

        gridLayout_6->addWidget(privacy_2, 0, 2, 1, 1);

        toolButton_3 = new QToolButton(page);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy3.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy3);
        toolButton_3->setMinimumSize(QSize(0, 40));
        toolButton_3->setMaximumSize(QSize(40, 16777215));
        toolButton_3->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_6->addWidget(toolButton_3, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_28 = new QLabel(page);
        label_28->setObjectName("label_28");

        gridLayout_5->addWidget(label_28, 0, 2, 1, 1);

        report = new QToolButton(page);
        report->setObjectName("report");
        report->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_5->addWidget(report, 0, 3, 1, 1);

        toolButton_4 = new QToolButton(page);
        toolButton_4->setObjectName("toolButton_4");
        sizePolicy3.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy3);
        toolButton_4->setMinimumSize(QSize(0, 40));
        toolButton_4->setMaximumSize(QSize(40, 16777215));
        toolButton_4->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_5->addWidget(toolButton_4, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        toolButton_5 = new QToolButton(page);
        toolButton_5->setObjectName("toolButton_5");
        sizePolicy3.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy3);
        toolButton_5->setMinimumSize(QSize(40, 40));
        toolButton_5->setMaximumSize(QSize(40, 40));
        toolButton_5->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_3->addWidget(toolButton_5, 0, 1, 1, 1);

        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        toolButton_6 = new QToolButton(page);
        toolButton_6->setObjectName("toolButton_6");
        sizePolicy3.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy3);
        toolButton_6->setMinimumSize(QSize(0, 40));
        toolButton_6->setMaximumSize(QSize(40, 40));
        toolButton_6->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout->addWidget(toolButton_6, 0, 0, 1, 1);

        label_7 = new QLabel(page);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_8 = new QGridLayout(page_2);
        gridLayout_8->setObjectName("gridLayout_8");
        aboutuser = new QLabel(page_2);
        aboutuser->setObjectName("aboutuser");
        aboutuser->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 6px;               \n"
"    background-color: #ffffff;  "));

        gridLayout_8->addWidget(aboutuser, 5, 0, 1, 2);

        emailuser = new QLabel(page_2);
        emailuser->setObjectName("emailuser");
        emailuser->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 6px;               \n"
"    background-color: #ffffff;  "));

        gridLayout_8->addWidget(emailuser, 7, 0, 1, 2);

        label_14 = new QLabel(page_2);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8(""));

        gridLayout_8->addWidget(label_14, 4, 0, 1, 2);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName("gridLayout_12");
        label_26 = new QLabel(page_2);
        label_26->setObjectName("label_26");

        gridLayout_12->addWidget(label_26, 0, 1, 1, 1);

        backButton_1 = new QToolButton(page_2);
        backButton_1->setObjectName("backButton_1");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(backButton_1->sizePolicy().hasHeightForWidth());
        backButton_1->setSizePolicy(sizePolicy5);
        backButton_1->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_12->addWidget(backButton_1, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_12, 2, 0, 1, 2);

        label_15 = new QLabel(page_2);
        label_15->setObjectName("label_15");
        label_15->setStyleSheet(QString::fromUtf8(""));

        gridLayout_8->addWidget(label_15, 6, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(verticalSpacer_3, 3, 0, 1, 1);

        label_20 = new QLabel(page_2);
        label_20->setObjectName("label_20");
        label_20->setStyleSheet(QString::fromUtf8(""));

        gridLayout_8->addWidget(label_20, 8, 0, 1, 2);

        dobuser = new QLabel(page_2);
        dobuser->setObjectName("dobuser");
        dobuser->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 6px;               \n"
"    background-color: #ffffff;  "));

        gridLayout_8->addWidget(dobuser, 10, 0, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Ignored);

        gridLayout_8->addItem(verticalSpacer_4, 11, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_9 = new QGridLayout(page_3);
        gridLayout_9->setObjectName("gridLayout_9");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_17 = new QLabel(page_3);
        label_17->setObjectName("label_17");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, label_17);

        backButton_2 = new QToolButton(page_3);
        backButton_2->setObjectName("backButton_2");
        sizePolicy5.setHeightForWidth(backButton_2->sizePolicy().hasHeightForWidth());
        backButton_2->setSizePolicy(sizePolicy5);
        backButton_2->setMinimumSize(QSize(0, 0));
        backButton_2->setMaximumSize(QSize(16777215, 16777215));
        backButton_2->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, backButton_2);


        gridLayout_9->addLayout(formLayout_2, 1, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_10 = new QLabel(page_3);
        label_10->setObjectName("label_10");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_10);

        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_9);

        current_pass = new QLineEdit(page_3);
        current_pass->setObjectName("current_pass");
        current_pass->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 2px;               \n"
"    background-color: #ffffff;  "));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, current_pass);

        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_11);

        new_pass = new QLineEdit(page_3);
        new_pass->setObjectName("new_pass");
        new_pass->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 2px;               \n"
"    background-color: #ffffff;  "));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, new_pass);

        label_12 = new QLabel(page_3);
        label_12->setObjectName("label_12");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_12);

        confirm_pass = new QLineEdit(page_3);
        confirm_pass->setObjectName("confirm_pass");
        confirm_pass->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 2px;               \n"
"    background-color: #ffffff;  "));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, confirm_pass);


        gridLayout_9->addLayout(formLayout, 7, 0, 2, 2);

        saveChanges = new QPushButton(page_3);
        saveChanges->setObjectName("saveChanges");
        saveChanges->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 149, 175);\n"
"  \n"
"        border-radius: 10px;\n"
"        padding: 6px 12px;\n"
"        font-weight: bold;\n"
""));

        gridLayout_9->addWidget(saveChanges, 10, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_8, 4, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_7, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Ignored);

        gridLayout_9->addItem(verticalSpacer, 9, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        gridLayout_9->addItem(verticalSpacer_2, 2, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName("gridLayout_13");
        user = new QLineEdit(page_3);
        user->setObjectName("user");
        user->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 2px;               \n"
"    background-color: #ffffff;  "));

        gridLayout_13->addWidget(user, 1, 0, 1, 1);

        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");

        gridLayout_13->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_13, 3, 0, 1, 2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayoutWidget = new QWidget(page_4);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 351, 40));
        gridLayout_10 = new QGridLayout(gridLayoutWidget);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        backButton_3 = new QToolButton(gridLayoutWidget);
        backButton_3->setObjectName("backButton_3");
        sizePolicy5.setHeightForWidth(backButton_3->sizePolicy().hasHeightForWidth());
        backButton_3->setSizePolicy(sizePolicy5);
        backButton_3->setMinimumSize(QSize(0, 0));
        backButton_3->setMaximumSize(QSize(16777215, 16777215));
        backButton_3->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_10->addWidget(backButton_3, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout_10->addWidget(label_5, 0, 1, 1, 1);

        label = new QLabel(page_4);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 65, 371, 341));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        reviewbox = new QPlainTextEdit(page_5);
        reviewbox->setObjectName("reviewbox");
        reviewbox->setGeometry(QRect(0, 70, 361, 281));
        reviewbox->setStyleSheet(QString::fromUtf8("border: 2px solid #000000; \n"
"    border-radius: 8px;        \n"
"    padding: 2px;               \n"
"    background-color: #ffffff;  "));
        gridLayoutWidget_2 = new QWidget(page_5);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 351, 40));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        backButton_4 = new QToolButton(gridLayoutWidget_2);
        backButton_4->setObjectName("backButton_4");
        sizePolicy5.setHeightForWidth(backButton_4->sizePolicy().hasHeightForWidth());
        backButton_4->setSizePolicy(sizePolicy5);
        backButton_4->setStyleSheet(QString::fromUtf8("\n"
"    border: none;           \n"
"    padding: 0px;                 \n"
"    background: transparent;     \n"
"    border-radius: 16px;  \n"
"  outline: none;               \n"
"    "));

        gridLayout_11->addWidget(backButton_4, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName("label_8");

        gridLayout_11->addWidget(label_8, 0, 1, 1, 1);

        revbutton = new QPushButton(page_5);
        revbutton->setObjectName("revbutton");
        revbutton->setGeometry(QRect(260, 360, 101, 31));
        revbutton->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 149, 175);\n"
"  \n"
"        border-radius: 10px;\n"
"        padding: 6px 12px;\n"
"        font-weight: bold;\n"
""));
        stackedWidget->addWidget(page_5);

        verticalLayout_2->addWidget(stackedWidget);


        gridLayout_7->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(profile);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(profile);
    } // setupUi

    void retranslateUi(QDialog *profile)
    {
        profile->setWindowTitle(QCoreApplication::translate("profile", "Dialog", nullptr));
        hello->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">HELLO,!!</span></p></body></html>", nullptr));
        toolButton_1->setText(QCoreApplication::translate("profile", "...", nullptr));
        about->setText(QCoreApplication::translate("profile", "...", nullptr));
        about_2->setText(QCoreApplication::translate("profile", "<html><head/><body><p>About your profile</p></body></html>", nullptr));
        toolButton_2->setText(QCoreApplication::translate("profile", "...", nullptr));
        edit->setText(QCoreApplication::translate("profile", "...", nullptr));
        edit_2->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Edit your Profile</p></body></html>", nullptr));
        privacy->setText(QCoreApplication::translate("profile", "...", nullptr));
        privacy_2->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Privacy policy</p></body></html>", nullptr));
        toolButton_3->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_28->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Report an issue</p></body></html>", nullptr));
        report->setText(QCoreApplication::translate("profile", "...", nullptr));
        toolButton_4->setText(QCoreApplication::translate("profile", "...", nullptr));
        toolButton_5->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_6->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Switch account</p></body></html>", nullptr));
        toolButton_6->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_7->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Log out</p></body></html>", nullptr));
        aboutuser->setText(QString());
        emailuser->setText(QString());
        label_14->setText(QCoreApplication::translate("profile", "Username:", nullptr));
        label_26->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">About You</span></p></body></html>", nullptr));
        backButton_1->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_15->setText(QCoreApplication::translate("profile", "Email:", nullptr));
        label_20->setText(QCoreApplication::translate("profile", "Date of birth:", nullptr));
        dobuser->setText(QString());
        label_17->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">Edit Your Profile</span></p></body></html>", nullptr));
        backButton_2->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_10->setText(QCoreApplication::translate("profile", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Password</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Current Password:</p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("profile", "New Password:", nullptr));
        label_12->setText(QCoreApplication::translate("profile", "Confirm Password:", nullptr));
        saveChanges->setText(QCoreApplication::translate("profile", "Save Changes", nullptr));
        label_4->setText(QCoreApplication::translate("profile", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Username</span></p></body></html>", nullptr));
        backButton_3->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_5->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">Privacy Policy</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("profile", "<html><head/><body><p>Your privacy is our priority. All personal</p><p>and financial information you provide is</p><p>stored securely and used solely to deliver,</p><p>improve your experience with our finance</p><p>tracking app. We do not sell or share your </p><p>data with third parties. Your information </p><p>is encrypted and handled in accordance to </p><p>industry best practices to ensure </p><p>confidentiality and security.</p><p><br/></p><p><br/></p></body></html>", nullptr));
        backButton_4->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_8->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">Review</span></p></body></html>", nullptr));
        revbutton->setText(QCoreApplication::translate("profile", "Send\342\236\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile: public Ui_profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
