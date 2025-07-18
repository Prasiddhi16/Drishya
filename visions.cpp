#include "visions.h"
#include "ui_visions.h" // This line would typically change based on your .ui file output
#include "insertt.h"
#include "profile.h"
#include "goaldata.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include<QPushButton>
#include<QGroupBox>
#include<QStackedWidget>
#include<QScrollArea>


Visions::Visions(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Visions) // Changed UI class instantiation
{
    ui->setupUi(this);

    //navigation bar
    // Create a horizontal layout to hold nav + UI content
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // --- Navigation panel (your existing code) ---
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Segoe UI", 10, QFont::Bold);
    QList<QPushButton*> buttons = {
        new QPushButton("🏠 Home"),
        new QPushButton("➕ Add Records"),
        new QPushButton("📈 Analytics"),
        new QPushButton("🎯 Goals"),
        new QPushButton("📋 Review"),
        new QPushButton("❓ Help")
    };
    for (auto btn : buttons) {
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setStyleSheet("color: #2c3e50; background-color: #e0e0e0; border: none; padding: 8px;");
        navLayout->addWidget(btn);
    }

    // --- Add nav and original UI to the layout ---
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget); // use existing .ui layout

    setCentralWidget(central); // Important!

    // Initialize with 6 empty GoalData objects
    goalDataList.resize(6);

    QList<QPushButton*> addButtons;
    addButtons << ui->add << ui->add_2 << ui->add_3
               << ui->add_4 << ui->add_5 << ui->add_6;

    for(QPushButton* button : addButtons) {
        connect(button, &QPushButton::clicked, this, &Visions::onAddButtonClicked); // Changed class scope
    }

    // Pass an empty GoalData to trigger default text display
    for (int i = 1; i <= 6; ++i) {
        updateGoalUI(i, GoalData());
    }

    // Initialize and load data from the database
    if (openDatabase()) {
        loadGoals();
    }
}


Visions::~Visions()
{
    closeDatabase();
    delete ui;
}


void Visions::onAddButtonClicked() {
    int slot = findNextAvailableSlot();
    if (slot == -1) {
        QMessageBox::information(this, "Limit Reached", "You have reached the maximum of 6 goals.");
        return;
    }

    Insertt *dialog = new Insertt(this);
    connect(dialog, &Insertt::goalSet, this, [=](const GoalData &data){ // Changed class scope
        handleGoalSet(slot, data);
    });
    dialog->exec();
}

// Changed class name in method definitions
void Visions::on_delete_1_clicked() { deleteGoal(1); }
void Visions::on_delete_2_clicked() { deleteGoal(2); }
void Visions::on_delete_3_clicked() { deleteGoal(3); }
void Visions::on_delete_4_clicked() { deleteGoal(4); }
void Visions::on_delete_5_clicked() { deleteGoal(5); }
void Visions::on_delete_6_clicked() { deleteGoal(6); }

// A generic slot to handle goal data from any button
void Visions::handleGoalSet(int goalIndex, const GoalData &data) {
    if (goalIndex < 1 || goalIndex > 6) return;

    goalDataList[goalIndex - 1] = data;
    updateGoalUI(goalIndex, data);
    saveGoal(goalIndex, data);
}

//print data

void Visions::updateGoalUI(int goalIndex, const GoalData &data)
{
    if (goalIndex < 1 || goalIndex > 6) return;

    QLabel* goalNameLabels[] = {
        nullptr, ui->goalNameLabel1, ui->goalNameLabel2, ui->goalNameLabel3,
        ui->goalNameLabel4, ui->goalNameLabel5, ui->goalNameLabel6
    };
    QLabel* incomeLabels[] = {
        nullptr, ui->incomeLabel1, ui->incomeLabel2, ui->incomeLabel3,
        ui->incomeLabel4, ui->incomeLabel5, ui->incomeLabel6
    };
    QLabel* downpaymentLabels[] = {
        nullptr, ui->downpaymentLabel1, ui->downpaymentLabel2, ui->downpaymentLabel3,
        ui->downpaymentLabel4, ui->downpaymentLabel5, ui->downpaymentLabel6
    };
    QLabel* remainingLabels[] = {
        nullptr, ui->remainingLabel1, ui->remainingLabel2, ui->remainingLabel3,
        ui->remainingLabel4, ui->remainingLabel5, ui->remainingLabel6
    };
    QLabel* monthLabels[] = {
        nullptr, ui->monthLabel1, ui->monthLabel2, ui->monthLabel3,
        ui->monthLabel4, ui->monthLabel5, ui->monthLabel6
    };
    QProgressBar* progressBars[] = {
        nullptr, ui->progressBar_1, ui->progressBar_2, ui->progressBar_3,
        ui->progressBar_4, ui->progressBar_5, ui->progressBar_6
    };
    QStackedWidget* stackedWidgets[] = {
        nullptr, ui->stackedWidget1, ui->stackedWidget2, ui->stackedWidget3,
        ui->stackedWidget4, ui->stackedWidget5, ui->stackedWidget6
    };


    if (data.name.isEmpty()) {
        stackedWidgets[goalIndex]->setCurrentIndex(0); // Show placeholder
        progressBars[goalIndex]->setVisible(false);
    }else { // Display actual goal data
        stackedWidgets[goalIndex]->setCurrentIndex(1);
        goalNameLabels[goalIndex]->setText(data.name.toUpper());
        incomeLabels[goalIndex]->setText(QString("Target amount: Rs %1").arg(data.incomeRequired));
        downpaymentLabels[goalIndex]->setText(QString("Current balance: Rs %1").arg(data.downpayment));
        remainingLabels[goalIndex]->setText(QString("Remaining sum: Rs %1").arg(data.incomeRequired - data.downpayment));
        monthLabels[goalIndex]->setText(QString("Monthly investment:Rs %1").arg(((data.incomeRequired - data.downpayment)/data.duration)));
        double progress = (data.incomeRequired == 0) ? 0 : (static_cast<double>(data.downpayment) / data.incomeRequired) * 100.0;
        progressBars[goalIndex]->setValue(static_cast<int>(progress));
        progressBars[goalIndex]->setVisible(true);
    }
}


int Visions::findNextAvailableSlot() {
    for (int i = 0; i < goalDataList.size(); ++i) {
        if (goalDataList[i].name.isEmpty()) {
            return i + 1; // Return 1-based index
        }
    }
    return -1; // No empty slots
}

//Database
// Changed class name in method definition
bool Visions::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("goals.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open database.");
        return false;
    }
    return true;
}

// Changed class name in method definition
void Visions::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}
// Changed class name in method definition
void Visions::loadGoals() {
    for (int i = 1; i <= 6; ++i) {
        updateGoalUI(i, GoalData());
    }

    for (int i = 0; i < goalDataList.size(); ++i) {
        goalDataList[i] = GoalData();
    }

    QSqlQuery query("SELECT goal_id, goal_name, required_amount, downpayment, time_limit FROM goals");
    int currentGoalCount = 0;

    while (query.next() && currentGoalCount < 6) {
        GoalData data;
        data.id = query.value("goal_id").toString();
        data.name = query.value("goal_name").toString();
        data.incomeRequired = query.value("required_amount").toDouble();
        data.downpayment = query.value("downpayment").toDouble();
        data.duration = query.value("time_limit").toInt();

        goalDataList[currentGoalCount] = data;
        currentGoalCount++;
    }

    for (int i = 0; i < goalDataList.size(); ++i) {
        updateGoalUI(i + 1, goalDataList[i]);
    }
    // After loading, ensure database reflects compacted goals
    // This handles cases where database might have gaps or old slots from previous runs
    QSqlQuery deleteOldGoalsQuery;
    deleteOldGoalsQuery.exec("DELETE FROM goals"); // Clear old table

    for (int i = 0; i < currentGoalCount; ++i) {
        saveGoal(i + 1, goalDataList[i]); // Resave with new 1-based sequential slots
    }

}

void Visions::saveGoal(int goalIndex, const GoalData &data) {
    QString goalId = data.id.isEmpty() ? QUuid::createUuid().toString(QUuid::WithoutBraces) : data.id;

    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO goals (goal_id, goal_name, required_amount, downpayment, time_limit) "
                  "VALUES (:goal_id, :goal_name, :required_amount, :downpayment, :time_limit)");
    query.bindValue(":goal_id", goalId);
    query.bindValue(":goal_name", data.name);
    query.bindValue(":required_amount", data.incomeRequired);
    query.bindValue(":downpayment", data.downpayment);
    query.bindValue(":time_limit", data.duration);

    if (!query.exec()) {
        qWarning() << "Failed to save goal:" << query.lastError().text();
    }
}


void Visions::deleteGoal(int goalIndex) {
    if (goalIndex < 1 || goalIndex > 6) return;

    QString goalId = goalDataList[goalIndex - 1].id;

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM goals WHERE goal_id = :id");
    deleteQuery.bindValue(":id", goalId);
    if (!deleteQuery.exec()) {
        qWarning() << "Failed to delete goal:" << deleteQuery.lastError().text();
    }

    //Step 1: Clear the goal from the in-memory list
    goalDataList[goalIndex - 1] = GoalData(); // Set it to an empty/default GoalData

    // Step 2: Shift remaining goals in the in-memory list
    // Iterate from the deleted slot up to the second-to-last slot (index 4 for 0-indexed vector)
    for (int i = goalIndex - 1; i < goalDataList.size() - 1; ++i) {
        goalDataList[i] = goalDataList[i+1]; // Copy data from the next slot to the current one
    }
    // Clear the very last slot (it now contains a duplicate or old data)
    goalDataList[goalDataList.size() - 1] = GoalData();

    // Step 3: Update all UI elements based on the shifted goalDataList
    // This will correctly display both shifted goals and default messages for empty slots
    for (int i = 0; i < goalDataList.size(); ++i) {
        updateGoalUI(i + 1, goalDataList[i]);
    }

    // Step 4: Update the database to reflect the new order
    // It's easiest to delete all goals and then re-insert them with their new 'slot' positions
    if (!deleteQuery.exec("DELETE FROM goals")) {
        qWarning() << "Failed to clear goals table:" << deleteQuery.lastError().text();
        return;
    }

    // Re-insert all goals from the (now shifted and compacted) goalDataList
    for (int i = 0; i < goalDataList.size(); ++i) {
        if (!goalDataList[i].name.isEmpty()) {
            saveGoal(i + 1, goalDataList[i]); // Save with new 1-based slot index
        }
    }
}

void Visions::on_toolButton_clicked()
{
    profile *p = new profile(this);
    p->setWindowFlags(Qt::Popup);
    QPoint globalPos = ui->toolButton->mapToGlobal(QPoint(0,ui->toolButton->height()));
    p->move(globalPos);
    p->show();
}
