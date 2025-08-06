#include "thirddialog.h"
#include "ui_thirddialog.h"
#include "secdialog.h"
#include "finaldial.h"
#include <QMessageBox>

thirdDialog::thirdDialog(const QString &userEmail,
                         int userId,
                         bool isMarried,
                         const QString &employment,
                         QWidget *parent)
    : QDialog(parent),
    ui(new Ui_thirdDialog),
    currentUserEmail(userEmail),
    currentUserId(userId),
    isMarried(isMarried),
    employment(employment)
{
    ui->setupUi(this);
}

thirdDialog::~thirdDialog()
{
    delete ui;
}

void thirdDialog::on_ryes_clicked()
{
    if (!(ui->rr->isChecked() || ui->rnr->isChecked())) {
        QMessageBox::information(this,
                                 "Selection Required",
                                 "Please select a residency option before proceeding.");
        qDebug() << "User prompted to select a residency option.";
        return;

    }


    bool isResident = ui->rr->isChecked(); // rr = Resident, rnr = Non-resident

    Finaldial = new finaldial(isMarried, employment, isResident, currentUserId, this);
    Finaldial->show();
    hide();

}

void thirdDialog::on_rno_clicked()
{
    secDialogInstance = new secDialog(currentUserEmail, currentUserId, isMarried, employment, this);
    secDialogInstance->show();
    hide();
}


