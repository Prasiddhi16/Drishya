#include "finaldial.h"
#include "ui_finaldial.h"

finaldial::finaldial( const QString &userEmail, int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::finaldial)
{
    ui->setupUi(this);
}

finaldial::~finaldial()
{
    delete ui;
}
