#ifndef FINALDIAL_H
#define FINALDIAL_H

#include <QDialog>

namespace Ui {
class finaldial;
}

class finaldial : public QDialog
{
    Q_OBJECT

public:
    explicit finaldial(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~finaldial();

private:
    Ui::finaldial *ui;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;

};

#endif // FINALDIAL_H
