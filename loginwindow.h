#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include<QtSql/QtSql>
#include"homewindow.h"


namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_pushButton_clicked();



   // void on_checkBox_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::loginWindow *ui;
    QSqlDatabase DBconnection;
    homeWindow *home_window;

};

#endif // LOGINWINDOW_H
