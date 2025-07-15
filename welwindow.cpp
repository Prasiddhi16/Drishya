#include "welwindow.h"
#include "ui_welwindow.h"
#include "homewindow.h"

welWindow::welWindow(const QString &userEmail, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);
    this->showMaximized();
}

welWindow::~welWindow()
{
    delete ui;
}

void welWindow::on_pushButton_clicked()
{
    home_window = new homeWindow(currentUserEmail, this);
    home_window->show();
    this->hide();
}
