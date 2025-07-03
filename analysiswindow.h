#ifndef ANALYSISWINDOW_H
#define ANALYSISWINDOW_H

#include <QMainWindow>
#include"budgetwindow.h"
#include"revwindow.h"
#include"weeklywindow.h"
#include"monthlywindow.h"

namespace Ui {
class analysisWindow;
}

class analysisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit analysisWindow(QWidget *parent = nullptr);
    ~analysisWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::analysisWindow *ui;
    budgetWindow *budget_window;
    revWindow*rev_window;
    weeklyWindow*weekly_window;
    monthlyWindow*monthly_window;

};
#endif // ANALYSISWINDOW_H
