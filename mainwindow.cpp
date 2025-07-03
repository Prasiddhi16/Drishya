#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_win_clicked()
{
    login_window = new  loginWindow(this);
    login_window->show();

}


void MainWindow::on_pushButton_2_clicked()
{
    signin_window=new signWindow(this);
    signin_window->show();

}

