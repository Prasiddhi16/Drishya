#ifndef FINALDIAL_H
#define FINALDIAL_H

#include <QDialog>

namespace Ui {
class finaldial;
}

class finaldial : public QDialog {
    Q_OBJECT

public:
    explicit finaldial(bool isMarried,
                       const QString &employment,
                       bool isResident,
                       int userId,
                       QWidget *parent = nullptr);
    ~finaldial();

private slots:
    void calculateTax();
    void on_pushButton_clicked();

private:
    Ui::finaldial *ui;
    bool isMarried;
    QString employment;
    bool isResident;
    int userId;
    QString currentUserName;
    QString currentUserEmail;

};

#endif // FINALDIAL_H
