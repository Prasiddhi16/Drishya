#include "finaldial.h"
#include "ui_finaldial.h"

finaldial::finaldial(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::finaldial)
{
    ui->setupUi(this);
}

finaldial::~finaldial()
{
    delete ui;
}
