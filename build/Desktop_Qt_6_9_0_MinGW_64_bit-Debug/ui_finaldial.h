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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_finaldial
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *finaldial)
    {
        if (finaldial->objectName().isEmpty())
            finaldial->setObjectName("finaldial");
        finaldial->resize(400, 300);
        buttonBox = new QDialogButtonBox(finaldial);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(finaldial);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, finaldial, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, finaldial, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(finaldial);
    } // setupUi

    void retranslateUi(QDialog *finaldial)
    {
        finaldial->setWindowTitle(QCoreApplication::translate("finaldial", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class finaldial: public Ui_finaldial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALDIAL_H
