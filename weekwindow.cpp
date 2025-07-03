#include "weekwindow.h"
#include "ui_weekwindow.h"

weekWindow::weekWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::weekWindow)
{
    ui->setupUi(this);
}

weekWindow::~weekWindow()
{
    delete ui;
}
