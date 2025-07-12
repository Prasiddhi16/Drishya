#ifndef SIGNWINDOW_H
#define SIGNWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "welwindow.h"

namespace Ui {
class signWindow;
}

class signWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit signWindow(QWidget *parent = nullptr);
    ~signWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signWindow *ui;
    QSqlDatabase DB_connection;
    welWindow *wel_window;
};

#endif // SIGNWINDOW_H
