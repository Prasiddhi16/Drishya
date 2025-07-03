#ifndef SIGNWINDOW_H
#define SIGNWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include"welwindow.h"

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
    welWindow *wel_window;

     QSqlDatabase DB_connection;
};

#endif // SIGNWINDOW_H
