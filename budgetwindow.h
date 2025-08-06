#ifndef BUDGETWINDOW_H
#define BUDGETWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
class budgetWindow;
}

class budgetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit budgetWindow(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~budgetWindow();



signals:
    void windowClosed();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::budgetWindow *ui;
    QString currentUserEmail;
    int currentUserId;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // BUDGETWINDOW_H
