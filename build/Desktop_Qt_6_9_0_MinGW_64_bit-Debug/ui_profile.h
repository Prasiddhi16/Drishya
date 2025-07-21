/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
    QLabel *label_2;
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
    QLabel *label_20;
    QLabel *label_18;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_19;
    QGridLayout *gridLayout_12;
    QLabel *label_26;
    QToolButton *backButton_1;
    QLabel *label_21;
    QLabel *label_13;
    QLabel *label_25;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_3;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_2;
    QLabel *label_17;
    QToolButton *backButton_2;
    QGridLayout *gridLayout_13;
    QLineEdit *user;
    QLabel *label_4;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *current_pass;
    QLabel *label_11;
    QLineEdit *new_pass;
    QLabel *label_12;
    QLineEdit *confirm_pass;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QPushButton *saveChanges;
    QSpacerItem *horizontalSpacer_8;
    QWidget *page_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_10;
    QToolButton *backButton_3;
    QLabel *label_5;
    QWidget *page_5;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_22;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_11;
    QToolButton *backButton_4;
    QLabel *label_8;
    QPushButton *pushButton;

    void setupUi(QDialog *profile)
    {
        if (profile->objectName().isEmpty())
            profile->setObjectName("profile");
        profile->resize(392, 424);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(profile->sizePolicy().hasHeightForWidth());
        profile->setSizePolicy(sizePolicy);
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
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_2);


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
        label_20 = new QLabel(page_2);
        label_20->setObjectName("label_20");

        gridLayout_8->addWidget(label_20, 8, 0, 1, 2);

        label_18 = new QLabel(page_2);
        label_18->setObjectName("label_18");

        gridLayout_8->addWidget(label_18, 12, 0, 1, 2);

        label_15 = new QLabel(page_2);
        label_15->setObjectName("label_15");

        gridLayout_8->addWidget(label_15, 6, 0, 1, 2);

        label_14 = new QLabel(page_2);
        label_14->setObjectName("label_14");

        gridLayout_8->addWidget(label_14, 4, 0, 1, 2);

        label_19 = new QLabel(page_2);
        label_19->setObjectName("label_19");

        gridLayout_8->addWidget(label_19, 5, 0, 1, 2);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName("gridLayout_12");
        label_26 = new QLabel(page_2);
        label_26->setObjectName("label_26");

        gridLayout_12->addWidget(label_26, 0, 1, 1, 1);

        backButton_1 = new QToolButton(page_2);
        backButton_1->setObjectName("backButton_1");

        gridLayout_12->addWidget(backButton_1, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_12, 2, 0, 1, 2);

        label_21 = new QLabel(page_2);
        label_21->setObjectName("label_21");

        gridLayout_8->addWidget(label_21, 10, 0, 1, 2);

        label_13 = new QLabel(page_2);
        label_13->setObjectName("label_13");

        gridLayout_8->addWidget(label_13, 7, 0, 1, 2);

        label_25 = new QLabel(page_2);
        label_25->setObjectName("label_25");

        gridLayout_8->addWidget(label_25, 11, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(verticalSpacer_3, 3, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_9 = new QGridLayout(page_3);
        gridLayout_9->setObjectName("gridLayout_9");
        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        gridLayout_9->addItem(verticalSpacer_2, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_17 = new QLabel(page_3);
        label_17->setObjectName("label_17");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, label_17);

        backButton_2 = new QToolButton(page_3);
        backButton_2->setObjectName("backButton_2");
        sizePolicy1.setHeightForWidth(backButton_2->sizePolicy().hasHeightForWidth());
        backButton_2->setSizePolicy(sizePolicy1);
        backButton_2->setMinimumSize(QSize(0, 0));
        backButton_2->setMaximumSize(QSize(16777215, 16777215));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, backButton_2);


        gridLayout_9->addLayout(formLayout_2, 1, 0, 1, 2);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName("gridLayout_13");
        user = new QLineEdit(page_3);
        user->setObjectName("user");

        gridLayout_13->addWidget(user, 1, 0, 1, 1);

        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");

        gridLayout_13->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_13, 3, 0, 1, 2);

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

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, current_pass);

        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_11);

        new_pass = new QLineEdit(page_3);
        new_pass->setObjectName("new_pass");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, new_pass);

        label_12 = new QLabel(page_3);
        label_12->setObjectName("label_12");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_12);

        confirm_pass = new QLineEdit(page_3);
        confirm_pass->setObjectName("confirm_pass");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, confirm_pass);


        gridLayout_9->addLayout(formLayout, 7, 0, 2, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_7, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Ignored);

        gridLayout_9->addItem(verticalSpacer, 9, 1, 1, 1);

        saveChanges = new QPushButton(page_3);
        saveChanges->setObjectName("saveChanges");

        gridLayout_9->addWidget(saveChanges, 10, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_8, 4, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayoutWidget = new QWidget(page_4);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 371, 35));
        gridLayout_10 = new QGridLayout(gridLayoutWidget);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        backButton_3 = new QToolButton(gridLayoutWidget);
        backButton_3->setObjectName("backButton_3");
        sizePolicy1.setHeightForWidth(backButton_3->sizePolicy().hasHeightForWidth());
        backButton_3->setSizePolicy(sizePolicy1);
        backButton_3->setMinimumSize(QSize(0, 0));
        backButton_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(backButton_3, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout_10->addWidget(label_5, 0, 1, 1, 1);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        plainTextEdit = new QPlainTextEdit(page_5);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(0, 70, 371, 251));
        label_22 = new QLabel(page_5);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(310, 390, 61, 31));
        gridLayoutWidget_2 = new QWidget(page_5);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 371, 35));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        backButton_4 = new QToolButton(gridLayoutWidget_2);
        backButton_4->setObjectName("backButton_4");

        gridLayout_11->addWidget(backButton_4, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName("label_8");

        gridLayout_11->addWidget(label_8, 0, 1, 1, 1);

        pushButton = new QPushButton(page_5);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 330, 101, 41));
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
        label_2->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">HELLO USERNAME!!</p></body></html>", nullptr));
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
        label_20->setText(QCoreApplication::translate("profile", "Date joined", nullptr));
        label_18->setText(QString());
        label_15->setText(QCoreApplication::translate("profile", "Email", nullptr));
        label_14->setText(QCoreApplication::translate("profile", "Username:", nullptr));
        label_19->setText(QString());
        label_26->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">About You</p></body></html>", nullptr));
        backButton_1->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_21->setText(QString());
        label_13->setText(QString());
        label_25->setText(QCoreApplication::translate("profile", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">Edit Your Profile</p></body></html>", nullptr));
        backButton_2->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_4->setText(QCoreApplication::translate("profile", "Username", nullptr));
        label_10->setText(QCoreApplication::translate("profile", "Password", nullptr));
        label_9->setText(QCoreApplication::translate("profile", "Current Password", nullptr));
        label_11->setText(QCoreApplication::translate("profile", "New Password", nullptr));
        label_12->setText(QCoreApplication::translate("profile", "Confirm Password", nullptr));
        saveChanges->setText(QCoreApplication::translate("profile", "Save Changes", nullptr));
        backButton_3->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_5->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">Privacy Policy</p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">Send</p></body></html>", nullptr));
        backButton_4->setText(QCoreApplication::translate("profile", "...", nullptr));
        label_8->setText(QCoreApplication::translate("profile", "<html><head/><body><p align=\"center\">Review/Report an issue</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("profile", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile: public Ui_profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
