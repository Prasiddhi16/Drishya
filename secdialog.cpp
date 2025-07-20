#include "secdialog.h"
#include "ui_secdialog.h"
#include "thirddialog.h"
#include "taxDialog.h"
#include <QMessageBox>

secDialog::secDialog(const QString &userEmail, int userId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui_secDialog),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_eyes_clicked()
{
    if (ui->radioButton->isChecked() || ui->radioButton_2->isChecked() || ui->radioButton_3->isChecked()) {
        thirddialog = new thirdDialog(currentUserEmail, currentUserId, this);
        thirddialog->show();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Selection Required");
        msgBox.setText("Please select an option before proceeding.");
        msgBox.setIcon(QMessageBox::Warning);

        QPushButton *okButton = msgBox.addButton("Got it!", QMessageBox::AcceptRole);
        msgBox.setDefaultButton(okButton);

        msgBox.setStyleSheet(
            "QLabel { min-width: 220px; font-size: 14px; color: #222; }"
            "QPushButton { font-size: 13px; padding: 6px 12px; background-color: #f0ad4e; border-radius: 4px; }"
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
