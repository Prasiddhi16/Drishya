#ifndef VISIONS_H
#define VISIONS_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QVector>
#include <QUuid>

#include "GoalData.h"
#include "profile.h"
#include <QProgressBar>
#include <QStackedWidget>
#include <QLabel>
class homeWindow;
class Insertt;

QT_BEGIN_NAMESPACE
namespace Ui {
class Visions;
}
QT_END_NAMESPACE

const int MAX_GOAL_SLOTS = 6;
class Visions : public QMainWindow
{
    Q_OBJECT

public:
    // This is the original constructor. No database parameter.
    explicit Visions(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~Visions();

public slots:
    void onGoalSet(int goalIndex, const GoalData &data);

private slots:
    void onAddButtonClicked();
    void on_toolButton_clicked();
    void openHome();
    void openRecordWindow();
    void openAnalytics();
    void openreview();
    void openhelp();

private:
    Ui::Visions *ui;
    QVector<GoalData> goalDataList;

    QSqlDatabase db; // <-- This is now a member variable

    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;

    homeWindow *home_window;

    QList<QLabel*> goalNameLabels;
    QList<QLabel*> incomeLabels;
    QList<QLabel*> downpaymentLabels;
    QList<QLabel*> remainingLabels;
    QList<QLabel*> monthLabels;
    QList<QProgressBar*> progressBars;
    QList<QStackedWidget*> stackedWidgets;
    QList<QPushButton*> addButtons;
    QList<QPushButton*> editButtons;
    QList<QPushButton*> deleteButtons;

    void setupUIElementLists();
    bool openDatabase(); // We will re-add this method
     void closeDatabase();
    void createGoalsTable();
    void loadGoals();
    void saveGoal(const GoalData &data);
    void editGoal(int goalIndex);
    void deleteGoal(int goalIndex);
    int findNextAvailableSlot();
    void updateGoalUI(int goalIndex, const GoalData &data);
    void clearGoalUI(int goalIndex);
    QLabel* getGoalNameLabel(int index);
    QLabel* getIncomeLabel(int index);
    QLabel* getDownpaymentLabel(int index);
    QLabel* getRemainingLabel(int index);
    QLabel* getMonthLabel(int index);
    QProgressBar* getProgressBar(int index);
    QStackedWidget* getStackedWidget(int index);
};

#endif // VISIONS_H
