#ifndef BUDGETWINDOW_H
#define BUDGETWINDOW_H

#include <QMainWindow>

namespace Ui {
class budgetWindow;
}

class budgetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit budgetWindow(QWidget *parent = nullptr);
    ~budgetWindow();

private:
    Ui::budgetWindow *ui;

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void windowClosed();
};

#endif // BUDGETWINDOW_H
