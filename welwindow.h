#ifndef WELWINDOW_H
#define WELWINDOW_H

#include <QMainWindow>
#include"analysiswindow.h"

namespace Ui {
class welWindow;
}

class welWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit welWindow(QWidget *parent = nullptr);
    ~welWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welWindow *ui;
    analysisWindow *analysis_window;
};

#endif // WELWINDOW_H
