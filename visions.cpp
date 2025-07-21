#include "visions.h"
#include "ui_visions.h"
#include "insertt.h"
#include "profile.h"
#include "homewindow.h"
#include "analysiswindow.h"
#include "RecordWindow.h"
#include "review.h"
#include"Help.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QGroupBox>
#include <QStackedWidget>
#include <QScrollArea>
#include <QUuid> // For generating unique IDs


Visions::Visions(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::Visions),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId) // Initialize user ID
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#131b39;");
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // --- Navigation Panel ---
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

    // Connect navigation buttons
    connect(buttons[0], &QPushButton::clicked, this, &Visions::openHome);
    connect(buttons[1], &QPushButton::clicked, this, &Visions::openRecordWindow);
    connect(buttons[2], &QPushButton::clicked, this, &Visions::openAnalytics);
    //connect(buttons[3], &QPushButton::clicked, this, &Visions::openvisions); // Ensure "Goals" button opens this window
    connect(buttons[4], &QPushButton::clicked, this, &Visions::openreview);
    connect(buttons[5], &QPushButton::clicked, this, &Visions::openhelp); // Assuming Help/Logout button closes this window

    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget); // Use existing .ui layout

    setCentralWidget(central);
    this->showMaximized();

    // Initialize with 6 empty GoalData objects
    // This ensures goalDataList has 6 elements corresponding to UI slots
    goalDataList.resize(6);

    // Connect Add buttons
    QList<QPushButton*> addButtons;
    addButtons << ui->add << ui->add_2 << ui->add_3
               << ui->add_4 << ui->add_5 << ui->add_6;

    for(QPushButton* button : addButtons) {
        connect(button, &QPushButton::clicked, this, &Visions::onAddButtonClicked);
    }

    // Connect Delete buttons
    connect(ui->delete_1, &QPushButton::clicked, this, &Visions::on_delete_1_clicked);
    connect(ui->delete_2, &QPushButton::clicked, this, &Visions::on_delete_2_clicked);
    connect(ui->delete_3, &QPushButton::clicked, this, &Visions::on_delete_3_clicked);
    connect(ui->delete_4, &QPushButton::clicked, this, &Visions::on_delete_4_clicked);
    connect(ui->delete_5, &QPushButton::clicked, this, &Visions::on_delete_5_clicked);
    connect(ui->delete_6, &QPushButton::clicked, this, &Visions::on_delete_6_clicked);

    //Connect Edit buttons
    connect(ui->edit1, &QPushButton::clicked, this, &Visions::on_edit1_clicked);
    connect(ui->edit2, &QPushButton::clicked, this, &Visions::on_edit2_clicked);
    connect(ui->edit3, &QPushButton::clicked, this, &Visions::on_edit3_clicked);
    connect(ui->edit4, &QPushButton::clicked, this, &Visions::on_edit4_clicked);
    connect(ui->edit5, &QPushButton::clicked, this, &Visions::on_edit5_clicked);
    connect(ui->edit6, &QPushButton::clicked, this, &Visions::on_edit6_clicked);

    // Database Initialization and Data Loading
    if (openDatabase()) {
        createGoalsTable(); // Ensure the table exists
        loadGoals(); // Load existing goals for the current user
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to open database for Visions window.");
    }
}

Visions::~Visions()
{
    closeDatabase();
    delete ui;
}

// --- Database Management ---
bool Visions::openDatabase() {
    // It's good practice to give connections unique names if managing multiple windows/connections
    QString connectionName = "visions_db_connection";
    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName); // Reuse existing connection
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName); // Create new connection
        QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
        db.setDatabaseName(dbPath);
        qDebug() << "Resolved DB Path in Visions:" << dbPath;
    }

    if (!db.isOpen()) { // Only try to open if it's not already open
        if (!db.open()) {
            qWarning() << "Failed to open database in Visions:" << db.lastError().text();
            return false;
        }
    }
    return true;
}

void Visions::closeDatabase() {
    if (db.isOpen()) {
        QString connectionName = db.connectionName();
        db.close();
        QSqlDatabase::removeDatabase(connectionName); // Remove the connection from the pool
        qDebug() << "Database connection for Visions closed and removed.";
    }
}

void Visions::createGoalsTable() {
    QSqlQuery query(db); // Associate query with our db member variable
    if (!query.exec("CREATE TABLE IF NOT EXISTS goals ("
                    "goal_id TEXT PRIMARY KEY,"
                    "user_id INTEGER NOT NULL,"
                    "goal_name TEXT,"
                    "required_amount REAL,"
                    "downpayment REAL,"
                    "time_limit INTEGER," // Changed to INTEGER as duration is likely int
                    "FOREIGN KEY (user_id) REFERENCES user(id))")) {
        qWarning() << "Failed to create goals table:" << query.lastError().text();
    }
}

// --- Goal Data Handling ---

// Load goals for the current user
void Visions::loadGoals() {
    // Clear in-memory list first
    for (int i = 0; i < goalDataList.size(); ++i) {
        goalDataList[i] = GoalData(); // Reset all to empty
    }

    QSqlQuery query(db); // Associate query with our db member variable
    query.prepare("SELECT goal_id, goal_name, required_amount, downpayment, time_limit "
                  "FROM goals WHERE user_id = :userId ORDER BY goal_id ASC"); // Order by goal_id or a slot index if you add one
    query.bindValue(":userId", currentUserId);

    if (!query.exec()) {
        qWarning() << "Failed to load goals:" << query.lastError().text();
        return;
    }

    int currentSlot = 0;
    while (query.next() && currentSlot < 6) {
        GoalData data;
        data.id = query.value("goal_id").toString();
        data.name = query.value("goal_name").toString();
        data.incomeRequired = query.value("required_amount").toDouble();
        data.downpayment = query.value("downpayment").toDouble();
        data.duration = query.value("time_limit").toInt();
        data.slotIndex = currentSlot + 1; // Assign slot index based on load order

        goalDataList[currentSlot] = data;
        currentSlot++;
    }

    // Update UI for all slots (some might remain empty if no data or less than 6 goals)
    for (int i = 0; i < goalDataList.size(); ++i) {
        updateGoalUI(i + 1, goalDataList[i]);
    }
}

// Save or Update a single goal
void Visions::saveGoal(const GoalData &data) {
    if (!db.isOpen()) {
        qWarning() << "Database not open for saving goal!";
        return;
    }

    QSqlQuery query(db); // Associate query with our db member variable

    // If data.id is empty, it's a new goal, generate a UUID
    QString actualGoalId = data.id.isEmpty() ? QUuid::createUuid().toString(QUuid::WithoutBraces) : data.id;

    // INSERT OR REPLACE works if goal_id is PRIMARY KEY
    query.prepare("INSERT OR REPLACE INTO goals "
                  "(goal_id, user_id, goal_name, required_amount, downpayment, time_limit) "
                  "VALUES (:goal_id, :user_id, :goal_name, :required_amount, :downpayment, :time_limit)");

    query.bindValue(":goal_id", actualGoalId);
    query.bindValue(":user_id", currentUserId); // Save with current user's ID
    query.bindValue(":goal_name", data.name);
    query.bindValue(":required_amount", data.incomeRequired);
    query.bindValue(":downpayment", data.downpayment);
    query.bindValue(":time_limit", data.duration);

    if (!query.exec()) {
        qWarning() << "Failed to save/update goal:" << query.lastError().text();
    } else {
        qDebug() << "Goal saved/updated successfully for user" << currentUserId << ":" << data.name;
        // If it was a new goal, update the GoalData object in goalDataList with the new actualGoalId
        // This is important for future edits/deletes to reference the correct ID.
        // You'll need to find the GoalData in goalDataList by its slotIndex and update its ID if it was new.
        // This might be better handled directly in onGoalSet.
    }
}

void Visions::deleteGoal(int goalIndex) {
    if (goalIndex < 1 || goalIndex > 6) return;
    if (!db.isOpen()) {
        qWarning() << "Database not open for deleting goal!";
        return;
    }

    QString goalIdToDelete = goalDataList[goalIndex - 1].id;

    if (goalIdToDelete.isEmpty()) {
        qDebug() << "No goal in slot" << goalIndex << "to delete.";
        return; // Nothing to delete from DB if slot is already empty
    }

    QSqlQuery deleteQuery(db); // Associate query with our db member variable
    deleteQuery.prepare("DELETE FROM goals WHERE goal_id = :id AND user_id = :userId");
    deleteQuery.bindValue(":id", goalIdToDelete);
    deleteQuery.bindValue(":userId", currentUserId);

    if (!deleteQuery.exec()) {
        qWarning() << "Failed to delete goal from DB:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Goal" << goalIdToDelete << "deleted from DB.";
    }

    // Step 1: Clear the goal from the in-memory list (removes goals at this slot)
    goalDataList[goalIndex - 1] = GoalData();

    // Step 2: Shift remaining goals in the in-memory list(fills the gap created by the deletion)

    for (int i = goalIndex - 1; i < goalDataList.size() - 1; ++i) {
        goalDataList[i] = goalDataList[i+1]; // Copy data from the next slot to the current one
        goalDataList[i].slotIndex = i + 1; // Update slot index after shifting
    }
    // Clear the very last slot (it now contains a duplicate or old data from the shifted list)
    goalDataList[goalDataList.size() - 1] = GoalData();

    // Step 3: Update all UI elements based on the shifted goalDataList
    for (int i = 0; i < goalDataList.size(); ++i) {
        updateGoalUI(i + 1, goalDataList[i]);
    }

    // Step 4: Re-sync the database to reflect the new order (more efficient approach)
    // Delete all current user's goals from DB, then re-insert the compacted list.
    // This is still a "delete all and re-insert" but scoped per user and only after a deletion.
    QSqlQuery clearUserGoalsQuery(db);
    clearUserGoalsQuery.prepare("DELETE FROM goals WHERE user_id = :userId");
    clearUserGoalsQuery.bindValue(":userId", currentUserId);
    if (!clearUserGoalsQuery.exec()) {
        qWarning() << "Failed to clear user's goals table for re-sync:" << clearUserGoalsQuery.lastError().text();
        return;
    }

    for (int i = 0; i < goalDataList.size(); ++i) {
        if (!goalDataList[i].isEmpty()) { // Only save non-empty goals
            saveGoal(goalDataList[i]); // Save the goal with its (potentially new) ID
        }
    }
    qDebug() << "Database re-synced after deletion and shift.";
}

// --- UI Slot Handlers ---

void Visions::onAddButtonClicked() {
    int slot = findNextAvailableSlot();
    if (slot == -1) {
        QMessageBox::information(this, "Limit Reached", "You have reached the maximum of 6 goals.");
        return;
    }

    Insertt *dialog = new Insertt(this);
    // Pass an empty GoalData to indicate it's a new goal
    dialog->setGoalData(GoalData());

    // Use a lambda to capture 'slot' and pass it to onGoalSet
    connect(dialog, &Insertt::goalSet, this, [this, slot](const GoalData &data){
        onGoalSet(slot, data);
    });
    dialog->exec();
    delete dialog; // Clean up the dialog after it closes
}

// Edit button handlers
void Visions::on_edit1_clicked() { editGoal(1); }
void Visions::on_edit2_clicked() { editGoal(2); }
void Visions::on_edit3_clicked() { editGoal(3); }
void Visions::on_edit4_clicked() { editGoal(4); }
void Visions::on_edit5_clicked() { editGoal(5); }
void Visions::on_edit6_clicked() { editGoal(6); }

// Generic edit goal function
void Visions::editGoal(int goalIndex) {
    if (goalIndex < 1 || goalIndex > 6) return;

    GoalData currentData = goalDataList[goalIndex - 1];
    if (currentData.isEmpty()) {
        QMessageBox::information(this, "No Goal", "There is no goal in this slot to edit. Use 'Add' instead.");
        return;
    }

    Insertt *dialog = new Insertt(this);
    dialog->setGoalData(currentData); // Pass existing data to the dialog

    connect(dialog, &Insertt::goalSet, this, [this, goalIndex](const GoalData &newData){
        onGoalSet(goalIndex, newData); // When dialog returns, update this slot
    });
    dialog->exec();
    delete dialog;
}


// A generic slot to handle goal data from any button (Add or Edit)
void Visions::onGoalSet(int goalIndex, const GoalData &data) {
    if (goalIndex < 1 || goalIndex > 6) return;

    GoalData updatedData = data; // Make a mutable copy of the data from the dialog

    if (!goalDataList[goalIndex - 1].id.isEmpty()) {
        updatedData.id = goalDataList[goalIndex - 1].id; // Keep existing ID for edits
    } else if (updatedData.id.isEmpty()) { // Only generate new UUID if both are empty
        updatedData.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
    updatedData.slotIndex = goalIndex; // Assign slot index

    goalDataList[goalIndex - 1] = updatedData; // Update the in-memory list
    updateGoalUI(goalIndex, updatedData);     // Update the UI for this slot
    saveGoal(updatedData);                    // Save/update to the database
}

// UI Update Helpers
void Visions::updateGoalUI(int goalIndex, const GoalData &data)
{
    if (goalIndex < 1 || goalIndex > 6) return;

    QLabel* goalNameLabel = getGoalNameLabel(goalIndex);
    QLabel* incomeLabel = getIncomeLabel(goalIndex);
    QLabel* downpaymentLabel = getDownpaymentLabel(goalIndex);
    QLabel* remainingLabel = getRemainingLabel(goalIndex);
    QLabel* monthLabel = getMonthLabel(goalIndex);
    QProgressBar* progressBar = getProgressBar(goalIndex);
    QStackedWidget* stackedWidget = getStackedWidget(goalIndex);

    // Get references to the Add, Edit, and Delete buttons for this specific goal slot
    QPushButton* addButton = nullptr;
    QPushButton* editButton = nullptr;
    QPushButton* deleteButton = nullptr;

    switch (goalIndex) {
    case 1: addButton = ui->add; editButton = ui->edit1; deleteButton = ui->delete_1; break;
    case 2: addButton = ui->add_2; editButton = ui->edit2; deleteButton = ui->delete_2; break;
    case 3: addButton = ui->add_3; editButton = ui->edit3; deleteButton = ui->delete_3; break;
    case 4: addButton = ui->add_4; editButton = ui->edit4; deleteButton = ui->delete_4; break;
    case 5: addButton = ui->add_5; editButton = ui->edit5; deleteButton = ui->delete_5; break;
    case 6: addButton = ui->add_6; editButton = ui->edit6; deleteButton = ui->delete_6; break;
    default: break;
    }


    if (!goalNameLabel || !incomeLabel || !downpaymentLabel || !remainingLabel || !monthLabel || !progressBar || !stackedWidget || !addButton || !editButton || !deleteButton) {
        qWarning() << "Failed to get UI elements for goal index:" << goalIndex;
        return;
    }

    if (data.isEmpty()) { // Display placeholder for empty slots
        stackedWidget->setCurrentIndex(0); // Show placeholder page
        progressBar->setVisible(false);

    } else { // Display actual goal data
        stackedWidget->setCurrentIndex(1); // Show data display page
        goalNameLabel->setText(data.name.toUpper());
        incomeLabel->setText(QString("Target amount: Rs %1").arg(data.incomeRequired, 0, 'f', 2));
        downpaymentLabel->setText(QString("Current balance: Rs %1").arg(data.downpayment, 0, 'f', 2));
        double remainingSum = data.incomeRequired - data.downpayment;
        remainingLabel->setText(QString("Remaining sum: Rs %1").arg(remainingSum, 0, 'f', 2));

        if (data.duration > 0) {
            double monthlyInvestment = remainingSum / data.duration;
            monthLabel->setText(QString("Monthly investment: Rs %1").arg(monthlyInvestment, 0, 'f', 2));
        } else {
            monthLabel->setText("Monthly investment: N/A (Duration is 0)");
        }

        double progress = (data.incomeRequired == 0) ? 0 : (data.downpayment / data.incomeRequired) * 100.0;
        progressBar->setValue(static_cast<int>(progress));
        progressBar->setVisible(true);

    }
}
// Helper to clear UI elements for a given slot (useful when a goal is deleted)
void Visions::clearGoalUI(int goalIndex) {
    updateGoalUI(goalIndex, GoalData()); // Pass an empty GoalData to show placeholder
}

int Visions::findNextAvailableSlot() {
    for (int i = 0; i < goalDataList.size(); ++i) {
        if (goalDataList[i].isEmpty()) {
            return i + 1; // Return 1-based index
        }
    }
    return -1; // No empty slots
}

// Generic Delete Goal (called by on_delete_X_clicked)
void Visions::on_delete_1_clicked() { deleteGoal(1); }
void Visions::on_delete_2_clicked() { deleteGoal(2); }
void Visions::on_delete_3_clicked() { deleteGoal(3); }
void Visions::on_delete_4_clicked() { deleteGoal(4); }
void Visions::on_delete_5_clicked() { deleteGoal(5); }
void Visions::on_delete_6_clicked() { deleteGoal(6); }

// Helper methods to get UI elements dynamically
QLabel* Visions::getGoalNameLabel(int index) {
    switch (index) {
    case 1: return ui->goalNameLabel1;
    case 2: return ui->goalNameLabel2;
    case 3: return ui->goalNameLabel3;
    case 4: return ui->goalNameLabel4;
    case 5: return ui->goalNameLabel5;
    case 6: return ui->goalNameLabel6;
    default: return nullptr;
    }
}
QLabel* Visions::getIncomeLabel(int index) {
    switch (index) {
    case 1: return ui->incomeLabel1;
    case 2: return ui->incomeLabel2;
    case 3: return ui->incomeLabel3;
    case 4: return ui->incomeLabel4;
    case 5: return ui->incomeLabel5;
    case 6: return ui->incomeLabel6;
    default: return nullptr;
    }
}
QLabel* Visions::getDownpaymentLabel(int index) {
    switch (index) {
    case 1: return ui->downpaymentLabel1;
    case 2: return ui->downpaymentLabel2;
    case 3: return ui->downpaymentLabel3;
    case 4: return ui->downpaymentLabel4;
    case 5: return ui->downpaymentLabel5;
    case 6: return ui->downpaymentLabel6;
    default: return nullptr;
    }
}
QLabel* Visions::getRemainingLabel(int index) {
    switch (index) {
    case 1: return ui->remainingLabel1;
    case 2: return ui->remainingLabel2;
    case 3: return ui->remainingLabel3;
    case 4: return ui->remainingLabel4;
    case 5: return ui->remainingLabel5;
    case 6: return ui->remainingLabel6;
    default: return nullptr;
    }
}
QLabel* Visions::getMonthLabel(int index) {
    switch (index) {
    case 1: return ui->monthLabel1;
    case 2: return ui->monthLabel2;
    case 3: return ui->monthLabel3;
    case 4: return ui->monthLabel4;
    case 5: return ui->monthLabel5;
    case 6: return ui->monthLabel6;
    default: return nullptr;
    }
}
QProgressBar* Visions::getProgressBar(int index) {
    switch (index) {
    case 1: return ui->progressBar_1;
    case 2: return ui->progressBar_2;
    case 3: return ui->progressBar_3;
    case 4: return ui->progressBar_4;
    case 5: return ui->progressBar_5;
    case 6: return ui->progressBar_6;
    default: return nullptr;
    }
}
QStackedWidget* Visions::getStackedWidget(int index) {
    switch (index) {
    case 1: return ui->stackedWidget1;
    case 2: return ui->stackedWidget2;
    case 3: return ui->stackedWidget3;
    case 4: return ui->stackedWidget4;
    case 5: return ui->stackedWidget5;
    case 6: return ui->stackedWidget6;
    default: return nullptr;
    }
}

// --- Navigation methods ---
void Visions::on_toolButton_clicked()
{
    profile *p = new profile(this);
    p->setWindowFlags(Qt::Popup);
    QPoint globalPos = ui->toolButton->mapToGlobal(QPoint(0,ui->toolButton->height()));
    p->move(globalPos);
    p->show();
}

void Visions::openHome()
{
    homeWindow *home_window_instance = new homeWindow(currentUserName, currentUserEmail, currentUserId, this);
    home_window_instance->show();
    this->hide();
}

void Visions::openAnalytics()
{
    analysisWindow *analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
    this->hide();
}

void Visions::openRecordWindow()
{
    RecordWindow* record_window = new RecordWindow(currentUserName, currentUserEmail, currentUserId, this);
    record_window->show();
    this->hide();
}

void Visions::openreview()
{
    review *review_win=new review(currentUserName, currentUserEmail, currentUserId, this);
    review_win->show();
    this->hide();
}
void Visions::openhelp()
{
    Help *help_win =new Help(currentUserName, currentUserEmail, currentUserId, this);
    help_win->show();
    this->hide();
}

