#ifndef REVWINDOW_H
#define REVWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QtWidgets>
#include<QtCharts>

namespace Ui {
class revWindow;
}

class revWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit revWindow(QWidget *parent = nullptr);
    ~revWindow();

private:
    Ui::revWindow *ui;
};

#endif // REVWINDOW_H
