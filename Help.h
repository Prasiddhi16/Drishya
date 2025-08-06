#ifndef HELP_H
#define HELP_H
class homeWindow;
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Help;
}
QT_END_NAMESPACE

class Help : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help(QString username, QString email, int userId, QWidget *parent);
     void openhelp();
    ~Help();

private slots:
    void openHome();
    void openAnalytics();
    void openreview();
    void openvisions();
    void openRecordWindow();
    void on_toolButton_clicked();

private:
    Ui::Help *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
    homeWindow* home_window;

};

#endif // HELP_H
