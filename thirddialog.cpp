#include "thirddialog.h"
#include "ui_thirddialog.h"
#include "secdialog.h"
#include "finaldial.h"
#include <QMessageBox>

thirdDialog::thirdDialog(const QString &userEmail, int userId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui_thirdDialog),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);
}

thirdDialog::~thirdDialog()
{
    delete ui;
}

void thirdDialog::on_ryes_clicked()
{
    if (ui->rr->isChecked() || ui->rnr->isChecked()) {
        Finaldial = new finaldial(currentUserEmail, currentUserId, this);
        Finaldial->show();
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

void thirdDialog::on_rno_clicked()
{
    secDialogInstance = new secDialog(currentUserEmail, currentUserId, this);
    secDialogInstance->show();
    hide();
}
