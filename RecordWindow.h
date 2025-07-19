#ifndef RECORD_WINDOW_H
#define RECORD_WINDOW_H

#include <QMainWindow>
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

private slots:
    void addRecord();
    void editIncome();
    void editExpense();
    void openHome();
    void openAnalytics();

    void openvisions();
    void openreview();

private:
    Ui::RecordWindow *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    homeWindow* home_window;

    // Dialog function for editing income/expense
    bool showEditDialog(const QString& title, const QString& labelText,
                        QString& amount, QString& sourceOrCategory, QString& timestamp);
};

#endif // RECORD_WINDOW_H
