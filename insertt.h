#ifndef INSERTT_H
#define INSERTT_H

#include <QDialog>
#include "goaldata.h" // Include GoalData struct definition

namespace Ui {
class Insertt;
}

class Insertt : public QDialog
{
    Q_OBJECT

public:
    explicit Insertt(QWidget *parent = nullptr);
    ~Insertt();
    // Used by Visions to pass existing goal data for editing
    void setGoalData(const GoalData &data);

signals:
    // This signal will carry the (potentially updated) GoalData back to Visions
    void goalSet(const GoalData &data);

private slots:
    void on_Save_clicked(); // This will now handle both new goal submission and edits

    void on_cancel_clicked();

private:
    Ui::Insertt *ui;
    GoalData currentGoalData; // To store the goal data being edited/added, including its ID
};

#endif // INSERTT_H
