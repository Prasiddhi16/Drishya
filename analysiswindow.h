#ifndef ANALYSISWINDOW_H
#define ANALYSISWINDOW_H

#include <QMainWindow>
#include "budgetwindow.h"
#include "revwindow.h"
#include "weeklywindow.h"
#include "monthlywindow.h"

// Forward declaration instead of including homewindow.h
class homeWindow;

namespace Ui {
class analysisWindow;
}

class analysisWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit analysisWindow(QString username, QString email, int userId, QWidget *parent = nullptr);
    ~analysisWindow();

private slots:
    void on_pushButton_clicked();   // Budget
    void on_pushButton_2_clicked(); // Review
    void on_pushButton_3_clicked(); // Weekly
    void on_pushButton_4_clicked(); // Monthly
    void openHome();
    void openRecordWindow();
    void openvisions();
    void openreview();
    void updateWeeklyExpense();
private:
    Ui::analysisWindow *ui;
     QString currentUserName;
    QString currentUserEmail;
    int currentUserId;  // ✅ New member variable


    homeWindow    *home_window;

    // Safe with forward declaration

    budgetWindow  *budget_window;
    revWindow     *rev_window;
    weeklyWindow  *weekly_window;
    monthlyWindow *monthly_window;
};

#endif // ANALYSISWINDOW_H
