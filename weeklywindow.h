#ifndef WEEKLYWINDOW_H
#define WEEKLYWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QtWidgets>
#include<QtCharts>

namespace Ui {
class weeklyWindow;
}

class weeklyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit weeklyWindow(QWidget *parent = nullptr);
    ~weeklyWindow();

private:
    Ui::weeklyWindow *ui;
};

#endif // WEEKLYWINDOW_H
