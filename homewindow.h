#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "analysiswindow.h"
class loginWindow;
QT_BEGIN_NAMESPACE
namespace Ui { class homeWindow; }
QT_END_NAMESPACE

class homeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit homeWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~homeWindow();

private slots:
    void openAnalytics();
void logoutAndResetSession ();   // Only Analytics wired up

private:
    Ui::homeWindow *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    analysisWindow *analysis_window;
    loginWindow* login_window = nullptr;
};

#endif // HOMEWINDOW_H
