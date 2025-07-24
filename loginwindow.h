#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QtSql>

// ✅ Forward declare before using
class homeWindow;

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
    void on_pushButton_2_clicked();

private:
    Ui::loginWindow *ui;
    QSqlDatabase DBconnection;
    homeWindow *home_window; // ✅ Use the forward-declared type here
};

#endif // LOGINWINDOW_H
