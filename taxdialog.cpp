#include "taxdialog.h"
#include "ui_taxdialog.h"
#include "secdialog.h"

taxDialog::taxDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui_taxDialog)
{
    ui->setupUi(this);
}

taxDialog::~taxDialog()
{
    delete ui;
}

void taxDialog::on_yes_btn_clicked()
{
    secdialog = new secDialog(this);
    secdialog->show();
    hide();
}

void taxDialog::on_no_btn_clicked()
{
    secdialog = new secDialog(this);
    secdialog->show();
    hide();
}

