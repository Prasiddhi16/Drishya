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
    QString currentUserEmail;
    int currentUserId;
    bool isMarried; // NEW: stores marital status
    secDialog *secdialog;
};

#endif // TAXDIALOG_H
