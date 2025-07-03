#ifndef MONTHLYWINDOW_H
#define MONTHLYWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QtWidgets>
#include<QtCharts>


namespace Ui {
class monthlyWindow;
}

class monthlyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit monthlyWindow(QWidget *parent = nullptr);
    ~monthlyWindow();

private:
    Ui::monthlyWindow *ui;
};

#endif // MONTHLYWINDOW_H
