#ifndef INSERTT_H
#define INSERTT_H

#include <QDialog>
#include <QSqlDatabase>
#include "goaldata.h"

namespace Ui {
class Insertt;
}

class Insertt : public QDialog
{
    Q_OBJECT

public:
    explicit Insertt(QWidget *parent = nullptr);
    ~Insertt();

private slots:
    void on_Save_clicked();
    void onSetGoalClicked();

private:
    Ui::Insertt *ui;

signals:
    void goalSet(const GoalData &data);
};

#endif // INSERTT_H
