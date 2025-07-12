#ifndef REVWINDOW_H
#define REVWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class revWindow;
}

class revWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit revWindow(const QString &userEmail, QWidget *parent = nullptr);
    ~revWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::revWindow *ui;
    QString currentUserEmail;
};

#endif // REVWINDOW_H
