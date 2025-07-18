#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "signwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_win_clicked()
{
    this->hide();
    login_window = new loginWindow();
    login_window->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    signin_window = new signWindow();
    signin_window->show();
}
