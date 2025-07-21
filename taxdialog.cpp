#include "taxdialog.h"
#include "ui_taxdialog.h"
#include "secdialog.h"

taxDialog::taxDialog(const QString &userEmail, int userId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui_taxDialog),
    currentUserEmail(userEmail),
    currentUserId(userId),
    isMarried(false) // default
{
    ui->setupUi(this);
}

taxDialog::~taxDialog()
{
    delete ui;
}

void taxDialog::on_yes_btn_clicked()
{
    isMarried = true;

    secdialog = new secDialog(currentUserEmail, currentUserId, isMarried, "Unknown", this);
    secdialog->show();
    hide();
}

void taxDialog::on_no_btn_clicked()
{
    isMarried = false;

    secdialog = new secDialog(currentUserEmail, currentUserId, isMarried, "Unknown", this);
    secdialog->show();
    hide();
}
