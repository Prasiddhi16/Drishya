#ifndef VISIONS_H
#define VISIONS_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Visions;
}
QT_END_NAMESPACE

class Visions : public QMainWindow
{
    Q_OBJECT

public:

    explicit Visions(QWidget *parent = nullptr);
    ~Visions();

public slots:
    void onGoalSet(const struct  GoalData &data);

private slots:
    void onAddButtonClicked();

    void on_delete_1_clicked();
    void on_delete_2_clicked();
    void on_delete_3_clicked();
    void on_delete_4_clicked();
    void on_delete_5_clicked();
    void on_delete_6_clicked();

    void handleGoalSet(int goalIndex, const GoalData &data);

    void on_toolButton_clicked();

private:
    Ui::Visions *ui;
    QVector<GoalData> goalDataList;
    QSqlDatabase db;

    // Database and data management methods
    bool openDatabase();
    void closeDatabase();
    void createGoalsTable();
    void loadGoals();
    void saveGoal(int goalIndex, const GoalData &data);
    void deleteGoal(int goalIndex);
    int findNextAvailableSlot();

    // Helper functions for UI updates
    void updateGoalUI(int goalIndex, const GoalData &data);
    void clearGoalUI(int goalIndex);
};
#endif // VISIONS_H
