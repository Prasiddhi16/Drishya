#ifndef BUDGETWINDOW_H
#define BUDGETWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class budgetWindow;
}
QT_END_NAMESPACE

class budgetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit budgetWindow(QWidget *parent = nullptr);
    ~budgetWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::budgetWindow *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // BUDGETWINDOW_H
