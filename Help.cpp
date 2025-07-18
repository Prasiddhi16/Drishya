#include "Help.h"
#include "ui_Help.h"

Help::Help(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help)
{
    ui->setupUi(this);
}

Help::~Help()
{
    delete ui;
}
