#ifndef WELWINDOW_H
#define WELWINDOW_H

#include <QMainWindow>
#include "homewindow.h"

namespace Ui {
class welWindow;
}

class welWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit welWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~welWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welWindow *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    homeWindow *home_window;
};

#endif // WELWINDOW_H
