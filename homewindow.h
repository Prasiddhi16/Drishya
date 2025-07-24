#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QLabel>

// Forward declarations
class loginWindow;
class analysisWindow;

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

    void openRecordWindow();
    void openvisions();
    void openreview();
    void openhelp();

private:
    Ui::homeWindow *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    QLabel *incomeAmount;
    QLabel *expenseAmount;
    QLabel *savingsAmount;
    QLabel *budgetAmount;

    loginWindow* login_window = nullptr;
    analysisWindow* analysis_window = nullptr;
};

#endif // HOMEWINDOW_H
