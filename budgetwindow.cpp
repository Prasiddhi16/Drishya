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

void budgetWindow::closeEvent(QCloseEvent* event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
