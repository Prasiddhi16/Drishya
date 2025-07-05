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
{   this->hide();
    budget_window = new  budgetWindow(nullptr);
    connect(budget_window, &budgetWindow::windowClosed,this, &analysisWindow::show);
    budget_window->show();

}


void analysisWindow::on_pushButton_2_clicked()
{   this->hide();
    rev_window= new revWindow(nullptr);
    connect(rev_window, &revWindow::windowClosed,this, &analysisWindow::show);
    rev_window->show();
}


void analysisWindow::on_pushButton_3_clicked()
{   this->hide();
    weekly_window= new weeklyWindow(nullptr);
    connect(weekly_window, &weeklyWindow::windowClosed,this, &analysisWindow::show);
    weekly_window->show();

}



void analysisWindow::on_pushButton_4_clicked()
{
    this->hide();
    monthly_window= new monthlyWindow(this);
    connect(monthly_window, &monthlyWindow::windowClosed,this, &analysisWindow::show);
    monthly_window->show();
}

