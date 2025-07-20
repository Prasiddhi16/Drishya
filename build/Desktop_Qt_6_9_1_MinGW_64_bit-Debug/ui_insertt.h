/********************************************************************************
** Form generated from reading UI file 'insertt.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTT_H
#define UI_INSERTT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Insertt
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Save;
    QPushButton *cancel;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QLabel *label_pic;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *goalNameEdit;
    QLabel *label_2;
    QLineEdit *incomeEdit;
    QLabel *label_3;
    QLineEdit *downpaymentEdit;
    QLabel *label_4;
    QLineEdit *durationEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Insertt)
    {
        if (Insertt->objectName().isEmpty())
            Insertt->setObjectName("Insertt");
        Insertt->resize(614, 296);
        Insertt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 219);"));
        gridLayout_3 = new QGridLayout(Insertt);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 20, -1, 4);
        widget = new QWidget(Insertt);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Save = new QPushButton(widget);
        Save->setObjectName("Save");
        Save->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #54e68a;\n"
"        color: white;\n"
"        border-radius: 10px;\n"
"        padding: 6px 12px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #45d17d;\n"
"	color:rgb(0,0,0);\n"
"    }\n"
""));

        horizontalLayout_2->addWidget(Save);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #f56464;\n"
"        color: white;\n"
"        border-radius: 10px;\n"
"        padding: 6px 12px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #e25050;\n"
"	color:rgb(0,0,0)\n"
"    }"));

        horizontalLayout_2->addWidget(cancel);


        gridLayout_3->addWidget(widget, 1, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        frame = new QFrame(Insertt);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(150, 35));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_pic = new QLabel(frame);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(0, 0, 151, 221));
        label_pic->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_pic->setPixmap(QPixmap(QString::fromUtf8("goal2.jpg")));

        gridLayout_4->addWidget(frame, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        groupBox = new QGroupBox(Insertt);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI\";\n"
"background-color: rgb(221, 193, 255);\n"
"radius:6px\n"
""));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(-1, 15, -1, 19);
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        goalNameEdit = new QLineEdit(groupBox);
        goalNameEdit->setObjectName("goalNameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, goalNameEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        incomeEdit = new QLineEdit(groupBox);
        incomeEdit->setObjectName("incomeEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, incomeEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        downpaymentEdit = new QLineEdit(groupBox);
        downpaymentEdit->setObjectName("downpaymentEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, downpaymentEdit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        durationEdit = new QLineEdit(groupBox);
        durationEdit->setObjectName("durationEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, durationEdit);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 5);

        retranslateUi(Insertt);
        QObject::connect(cancel, &QPushButton::clicked, Insertt, qOverload<>(&QDialog::close));
        QObject::connect(Save, &QPushButton::clicked, Insertt, qOverload<>(&QDialog::update));

        QMetaObject::connectSlotsByName(Insertt);
    } // setupUi

    void retranslateUi(QDialog *Insertt)
    {
        Insertt->setWindowTitle(QCoreApplication::translate("Insertt", "Dialog", nullptr));
        Save->setText(QCoreApplication::translate("Insertt", "SET GOAL", nullptr));
        cancel->setText(QCoreApplication::translate("Insertt", "CANCEL", nullptr));
        label_pic->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Insertt", "Vision", nullptr));
        label->setText(QCoreApplication::translate("Insertt", "Name of your goal:", nullptr));
        goalNameEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("Insertt", "Income required:", nullptr));
        label_3->setText(QCoreApplication::translate("Insertt", "Downpayment:", nullptr));
        label_4->setText(QCoreApplication::translate("Insertt", "<html><head/><body><p>Time limit:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Insertt: public Ui_Insertt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTT_H
