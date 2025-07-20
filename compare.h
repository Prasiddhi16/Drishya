#ifndef COMPARE_H
#define COMPARE_H

#include <QMainWindow>

namespace Ui {
class compare;
}

class compare : public QMainWindow
{
    Q_OBJECT

public:
    explicit compare(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~compare();

private:
    Ui::compare *ui;
    void setupChart();
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
};

#endif // COMPARE_H
