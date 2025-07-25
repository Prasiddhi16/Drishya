#ifndef PROFILE_H
#define PROFILE_H
#include "loginwindow.h"


#include <QDialog>
#include <QSqlDatabase>
#include <QLineEdit>

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:


    explicit profile(int userId, const QString &userEmail, QWidget *parent = nullptr);

    ~profile();

private slots:
    void on_saveChanges_clicked();

    void on_revbutton_clicked();
    void on_logout_clicked();



private:
    Ui::profile *ui;
    int m_userId;
    QString m_userEmail;
    QSqlDatabase m_db;
 loginWindow* login_window = nullptr;
    // Helper functions
    void loadUserData();
    QString hashPassword(const QString &password);
    void setupPasswordEyeToggle(QLineEdit *lineEdit);
};

#endif // PROFILE_H
