#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

class finaldial;
class secDialog;

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(const QString &userEmail,
                         int userId,
                         bool isMarried,
                         const QString &employment,
                         QWidget *parent = nullptr);
    ~thirdDialog();

private slots:
    void on_ryes_clicked();
    void on_rno_clicked();

private:
    class Ui_thirdDialog *ui;
    finaldial *Finaldial;
    secDialog *secDialogInstance;
    QString currentUserName;
    QString currentUserEmail;
    bool isMarried;
    QString employment;
    int currentUserId;
};

#endif // THIRDDIALOG_H
