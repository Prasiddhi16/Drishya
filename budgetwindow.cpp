#include "budgetwindow.h"
#include "ui_budgetwindow.h"

budgetWindow::budgetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::budgetWindow)
{
    ui->setupUi(this);
}

budgetWindow::~budgetWindow()
{
    delete ui;
}
