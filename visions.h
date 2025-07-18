#ifndef VISIONS_H
#define VISIONS_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
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
