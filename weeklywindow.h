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
    explicit weeklyWindow(const QString &userEmail, QWidget *parent = nullptr);
    ~weeklyWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::weeklyWindow *ui;
    QString currentUserEmail;

};

#endif // WEEKLYWINDOW_H
