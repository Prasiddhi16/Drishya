#include "analysiswindow.h"
#include "ui_analysiswindow.h"

analysisWindow::analysisWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::analysisWindow)
{
    ui->setupUi(this);
}

analysisWindow::~analysisWindow()
{
    delete ui;
}

void analysisWindow::on_pushButton_clicked()
{
    budget_window = new  budgetWindow(this);
    budget_window->show();

}


void analysisWindow::on_pushButton_2_clicked()
{
    rev_window= new revWindow(this);
    rev_window->show();
}


void analysisWindow::on_pushButton_3_clicked()
{    weekly_window= new weeklyWindow(this);
     weekly_window->show();
}




void analysisWindow::on_pushButton_4_clicked()
{
    monthly_window= new monthlyWindow(this);
    monthly_window->show();
}

