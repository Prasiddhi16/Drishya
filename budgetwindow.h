#ifndef BUDGETWINDOW_H
#define BUDGETWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class budgetWindow;
}

class budgetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit budgetWindow(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~budgetWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::budgetWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QString currentUserEmail;
     int currentUserId;
};

#endif // BUDGETWINDOW_H
