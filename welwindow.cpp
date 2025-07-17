#include "welwindow.h"
#include "ui_welwindow.h"
#include "homewindow.h"

welWindow::welWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welWindow)
    , currentUserName(userName)
    , currentUserEmail(userEmail)
    , currentUserId(userId)
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
    home_window = new homeWindow(currentUserName, currentUserEmail, currentUserId, this);
    home_window->show();
    this->hide();
}
