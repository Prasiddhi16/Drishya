#include "welwindow.h"
#include "ui_welwindow.h"

welWindow::welWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welWindow)
{
    ui->setupUi(this);
}

welWindow::~welWindow()
{
    delete ui;
}

void welWindow::on_pushButton_clicked()
{
    analysis_window = new  analysisWindow(this);
    analysis_window->show();
    this->hide();

}

