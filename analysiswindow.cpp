#include "analysiswindow.h"
#include "ui_analysiswindow.h"

analysisWindow::analysisWindow(const QString &userEmail, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::analysisWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);
}

analysisWindow::~analysisWindow()
{
    delete ui;
}

// 📊 Budget View
void analysisWindow::on_pushButton_clicked()
{
    this->hide();
    budget_window = new budgetWindow(currentUserEmail, this);
    connect(budget_window, &budgetWindow::windowClosed, this, &analysisWindow::show);
    budget_window->show();
}

// 📋 Review Summary
void analysisWindow::on_pushButton_2_clicked()
{
    this->hide();
    rev_window = new revWindow(currentUserEmail, this);
    connect(rev_window, &revWindow::windowClosed, this, &analysisWindow::show);
    rev_window->show();
}

// 📅 Weekly Breakdown
void analysisWindow::on_pushButton_3_clicked()
{
    this->hide();
    weekly_window = new weeklyWindow(currentUserEmail, this);
    connect(weekly_window, &weeklyWindow::windowClosed, this, &analysisWindow::show);
    weekly_window->show();
}

// 📆 Monthly Summary
void analysisWindow::on_pushButton_4_clicked()
{
    this->hide();
    monthly_window = new monthlyWindow(currentUserEmail, this);
    connect(monthly_window, &monthlyWindow::windowClosed, this, &analysisWindow::show);
    monthly_window->show();
}
