#ifndef VISIONS_H
#define VISIONS_H

// Core Qt headers
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QVector>
#include <QUuid> // Needed for UUID generation for goal_id

#include "GoalData.h"
#include "profile.h"
// Include headers for UI widgets used in member function declarations
#include <QProgressBar>
#include <QStackedWidget>
#include <QLabel>

// Forward declarations for classes used only as pointers (to avoid circular includes)
class homeWindow;
class Insertt; // Declare Insertt class

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
    explicit Visions(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr); // Added default parent value
    ~Visions();

public slots:
    void onGoalSet(int goalIndex, const GoalData &data); // GoalData is now known

private slots:
    void onAddButtonClicked();
    void on_toolButton_clicked();
    void openHome();
    void openRecordWindow();
    void openAnalytics();
    //void openvisions();
    void openreview();
    void openhelp();

private:
    Ui::Visions *ui;
    QVector<GoalData> goalDataList;
    QSqlDatabase db;
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

    // Add this method to initialize the lists above
    void setupUIElementLists();

    // Database and data management methods
    bool openDatabase();
    void closeDatabase();
    void createGoalsTable();
    void loadGoals();
    void saveGoal(const GoalData &data); // GoalData is now known
    void editGoal(int goalIndex);
    void deleteGoal(int goalIndex);
    int findNextAvailableSlot();

    // Helper functions for UI updates
    void updateGoalUI(int goalIndex, const GoalData &data); // GoalData is now known
    void clearGoalUI(int goalIndex);

    // Utility to get UI labels/widgets based on index
    QLabel* getGoalNameLabel(int index);
    QLabel* getIncomeLabel(int index);
    QLabel* getDownpaymentLabel(int index);
    QLabel* getRemainingLabel(int index);
    QLabel* getMonthLabel(int index);
    QProgressBar* getProgressBar(int index);
    QStackedWidget* getStackedWidget(int index);


};

#endif // VISIONS_H

