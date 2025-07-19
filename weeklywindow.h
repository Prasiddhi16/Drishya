#ifndef WEEKLYWINDOW_H
#define WEEKLYWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class weeklyWindow;
}

class weeklyWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit weeklyWindow(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~weeklyWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::weeklyWindow *ui;
    QString currentUserEmail;
    int currentUserId;

};

#endif // WEEKLYWINDOW_H
