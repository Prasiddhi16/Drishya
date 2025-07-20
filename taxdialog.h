#ifndef TAXDIALOG_H
#define TAXDIALOG_H

#include <QDialog>


class secDialog;

class Ui_taxDialog;

class taxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit taxDialog(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~taxDialog();

private slots:
    void on_yes_btn_clicked();
    void on_no_btn_clicked();

private:
    Ui_taxDialog *ui;
    secDialog *secdialog;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;
};

#endif // TAXDIALOG_H
