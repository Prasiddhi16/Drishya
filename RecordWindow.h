#ifndef RECORD_WINDOW_H
#define RECORD_WINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
class homeWindow;
QT_BEGIN_NAMESPACE
namespace Ui { class RecordWindow; }
QT_END_NAMESPACE

class RecordWindow : public QMainWindow
{
    Q_OBJECT

public:

    RecordWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~RecordWindow();
signals:
    void expenseAdded();

private slots:
    void addRecord();
    void editIncome();
    void editExpense();
    void showIncomeTable();
     void showExpenseTable();
    void openHome();
    void openAnalytics();
    void openhelp();
    void openvisions();
    void openreview();

private:
    Ui::RecordWindow *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    QSqlDatabase DB_connection;

    homeWindow* home_window;

    // Dialog function for editing income/expense
    bool showEditDialog(const QString& title, const QString& labelText,
                        QString& amount, QString& sourceOrCategory, QString& timestamp);
};

#endif // RECORD_WINDOW_H
