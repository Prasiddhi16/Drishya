#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

class finaldial;
class secDialog;

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);
    ~thirdDialog();

private slots:
    void on_ryes_clicked();
    void on_rno_clicked();

private:
    class Ui_thirdDialog *ui;
    finaldial *Finaldial;
    secDialog *secDialogInstance;
};

#endif // THIRDDIALOG_H
