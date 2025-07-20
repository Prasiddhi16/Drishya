#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include<taxdialog.h>
class thirdDialog;
class taxDialog;

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~secDialog();

private slots:
    void on_eyes_clicked();
    void on_eno_clicked();

private:
    class Ui_secDialog *ui;  // Use generated class directly
    thirdDialog *thirddialog;
        taxDialog *TaxdialogInstance;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
};

#endif // SECDIALOG_H
