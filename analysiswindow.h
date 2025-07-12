#ifndef ANALYSISWINDOW_H
#define ANALYSISWINDOW_H

#include <QMainWindow>
#include "budgetwindow.h"
#include "revwindow.h"
#include "weeklywindow.h"
#include "monthlywindow.h"

namespace Ui {
class analysisWindow;
}

class analysisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit analysisWindow(const QString &userEmail, QWidget *parent = nullptr);
    ~analysisWindow();

private slots:
    void on_pushButton_clicked();   // Budget
    void on_pushButton_2_clicked(); // Review
    void on_pushButton_3_clicked(); // Weekly
    void on_pushButton_4_clicked(); // Monthly

private:
    Ui::analysisWindow *ui;
    QString currentUserEmail;

    budgetWindow   *budget_window;
    revWindow      *rev_window;
    weeklyWindow   *weekly_window;
    monthlyWindow  *monthly_window;
};

#endif // ANALYSISWINDOW_H
