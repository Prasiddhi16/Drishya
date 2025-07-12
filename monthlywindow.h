#ifndef MONTHLYWINDOW_H
#define MONTHLYWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class monthlyWindow;
}

class monthlyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit monthlyWindow(const QString &userEmail, QWidget *parent = nullptr);
    ~monthlyWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::monthlyWindow *ui;
    QString currentUserEmail;
};

#endif // MONTHLYWINDOW_H
