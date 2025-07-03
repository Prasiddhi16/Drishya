#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"loginwindow.h"
#include"signwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_win_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    loginWindow *login_window;
    signWindow *signin_window;

};
#endif // MAINWINDOW_H
