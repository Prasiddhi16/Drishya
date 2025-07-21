/********************************************************************************
** Form generated from reading UI file 'finaldial.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALDIAL_H
#define UI_FINALDIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_finaldial
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *Label;

    void setupUi(QDialog *finaldial)
    {
        if (finaldial->objectName().isEmpty())
            finaldial->setObjectName("finaldial");
        finaldial->resize(400, 300);
        horizontalLayoutWidget = new QWidget(finaldial);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, 239, 401, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        horizontalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout->addItem(verticalSpacer_2);

        Label = new QLabel(finaldial);
        Label->setObjectName("Label");
        Label->setGeometry(QRect(6, 90, 381, 91));

        retranslateUi(finaldial);

        QMetaObject::connectSlotsByName(finaldial);
    } // setupUi

    void retranslateUi(QDialog *finaldial)
    {
        finaldial->setWindowTitle(QCoreApplication::translate("finaldial", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("finaldial", "Ok", nullptr));
        Label->setText(QCoreApplication::translate("finaldial", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class finaldial: public Ui_finaldial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALDIAL_H
