#include "secdialog.h"
#include "ui_secdialog.h"
#include "thirddialog.h"
#include "taxDialog.h"
#include <QMessageBox>
secDialog::secDialog(const QString &userEmail,
                     int userId,
                     bool isMarried,
                     const QString &employment,
                     QWidget *parent)
    : QDialog(parent),
    ui(new Ui_secDialog),
    currentUserEmail(userEmail),
    currentUserId(userId),
    isMarried(isMarried),
    employment(employment)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_eyes_clicked()
{
    QString employment;
if (ui->radioButton->isChecked())        employment = "Employed";
else if (ui->radioButton_2->isChecked()) employment = "Self-employed";
else if (ui->radioButton_3->isChecked()) employment = "Unemployed";

 if (ui->radioButton->isChecked() || ui->radioButton_2->isChecked() || ui->radioButton_3->isChecked()) {
        thirddialog = new thirdDialog(currentUserEmail,currentUserId,isMarried,employment, this);
        thirddialog->show();
        hide();

    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Selection Required");
        msgBox.setText("Please select an option");
      msgBox.setIcon(QMessageBox::Warning);

        QPushButton *okButton = msgBox.addButton("Got it!", QMessageBox::AcceptRole);
        msgBox.setDefaultButton(okButton);

        msgBox.setStyleSheet(
            "QLabel { min-width: 200px; font-size: 13px; color: #222; }"
            "QPushButton { font-size: 12px; padding: 4px 10px; background-color: #f0ad4e; border-radius: 4px; }"
            );
        msgBox.exec();

    }
}

void secDialog::on_eno_clicked()
{
    TaxdialogInstance = new taxDialog(currentUserEmail, currentUserId, this);
    TaxdialogInstance->show();
    hide();
}


