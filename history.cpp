#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}
