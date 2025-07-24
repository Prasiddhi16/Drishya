#ifndef PROFILE_H
#define PROFILE_H
#include "loginwindow.h"


#include <QDialog>
#include <QSqlDatabase> // Required for QSqlDatabase member
#include <QLineEdit> // Required for setupPasswordEyeToggle

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
    int m_userId;          // Stores the ID of the current user
    QString m_userEmail;   // Stores the email of the current user (could also store username)
    QSqlDatabase m_db;     // Member to manage the database connection for this window
 loginWindow* login_window = nullptr;
    // Helper functions
    void loadUserData();                               // Function to load and display user data
    QString hashPassword(const QString &password);     // Function to hash passwords
    void setupPasswordEyeToggle(QLineEdit *lineEdit);  // Function to add the eye icon to password fields
};

#endif // PROFILE_H
