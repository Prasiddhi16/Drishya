#include "visions.h"
#include "ui_visions.h"
#include "insertt.h"
#include "profile.h"
#include "homewindow.h"
#include "analysiswindow.h"
#include "RecordWindow.h"
#include "loginwindow.h"
#include "review.h"
#include "Help.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include<QPixmap>
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
#include <QDir>
#include <QCoreApplication>
#include <QSettings> // For QSettings

Visions::Visions(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::Visions),
    goalDataList(MAX_GOAL_SLOTS),
    db(QSqlDatabase::addDatabase("QSQLITE", "visions_db_connection")), // Re-add connection here
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    ui->setupUi(this);

    // Call this FIRST to populate your QList<QPushButton*> and other QList<QWidget*> members
    setupUIElementLists();

    // Initialize slotIndex for each GoalData object
    for (int i = 0; i < MAX_GOAL_SLOTS; ++i) {
        goalDataList[i].slotIndex = i + 1;
    }

    this->setStyleSheet("background-color:#131b39;");
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // Navigation Panel
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
        new QPushButton("🎯 Goals"), // This is the button for the current Visions window
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
    // buttons[3] ("Goals") already points to this window, no connection needed here to re-open itself
    connect(buttons[4], &QPushButton::clicked, this, &Visions::openreview);
    connect(buttons[5], &QPushButton::clicked, this, &Visions::openhelp);

    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget); // Use existing .ui layout

    setCentralWidget(central);
    this->showMaximized();

    QPixmap pix(":/img/img/profileicon.png");
    ui->toolButton->setIcon(QIcon(pix));
    ui->toolButton->setIconSize(ui->toolButton->size());

    // Initialize with 6 empty GoalData objects
    // This ensures goalDataList has 6 elements corresponding to UI slots
    const int MAX_GOAL_SLOTS = 6;


    // Connect Add buttons
    for(QPushButton* button : addButtons) {
        connect(button, &QPushButton::clicked, this, &Visions::onAddButtonClicked);
    }


    for (int i = 0; i < MAX_GOAL_SLOTS; ++i) {
        // Connect delete buttons using a lambda directly to deleteGoal
        connect(deleteButtons[i], &QPushButton::clicked, this, [this, i]() {
            deleteGoal(i + 1); // Pass 1-based index
        });

        // Connect edit buttons using a lambda directly to editGoal
        connect(editButtons[i], &QPushButton::clicked, this, [this, i]() {
            editGoal(i + 1); // Pass 1-based index
        });
    }
    if (openDatabase()) {
        createGoalsTable();
        loadGoals();
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to open database for Visions window.");
    }
}

Visions::~Visions()
{
    closeDatabase();
    delete ui;
}


void Visions::setupUIElementLists() {
    // Populate QLabel lists
    goalNameLabels << ui->goalNameLabel1 << ui->goalNameLabel2 << ui->goalNameLabel3
                   << ui->goalNameLabel4 << ui->goalNameLabel5 << ui->goalNameLabel6;

    incomeLabels << ui->incomeLabel1 << ui->incomeLabel2 << ui->incomeLabel3
                 << ui->incomeLabel4 << ui->incomeLabel5 << ui->incomeLabel6;

    downpaymentLabels << ui->downpaymentLabel1 << ui->downpaymentLabel2 << ui->downpaymentLabel3
                      << ui->downpaymentLabel4 << ui->downpaymentLabel5 << ui->downpaymentLabel6;

    remainingLabels << ui->remainingLabel1 << ui->remainingLabel2 << ui->remainingLabel3
                    << ui->remainingLabel4 << ui->remainingLabel5 << ui->remainingLabel6;

    monthLabels << ui->monthLabel1 << ui->monthLabel2 << ui->monthLabel3
                << ui->monthLabel4 << ui->monthLabel5 << ui->monthLabel6;

    // Populate QProgressBar list
    progressBars << ui->progressBar_1 << ui->progressBar_2 << ui->progressBar_3
                 << ui->progressBar_4 << ui->progressBar_5 << ui->progressBar_6;

    // Populate QStackedWidget list
    stackedWidgets << ui->stackedWidget1 << ui->stackedWidget2 << ui->stackedWidget3
                   << ui->stackedWidget4 << ui->stackedWidget5 << ui->stackedWidget6;

    // Populate QPushButton lists
    addButtons << ui->add << ui->add_2 << ui->add_3
               << ui->add_4 << ui->add_5 << ui->add_6;

    editButtons << ui->edit1 << ui->edit2 << ui->edit3
                << ui->edit4 << ui->edit5 << ui->edit6;

    deleteButtons << ui->delete_1 << ui->delete_2 << ui->delete_3
                  << ui->delete_4 << ui->delete_5 << ui->delete_6;
}

// Database Management
bool Visions::openDatabase() {
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    if (!db.isOpen()) {
        if (!db.open()) {
            qWarning() << "Failed to open Visions database:" << db.lastError().text();
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

//Goal Data Handling
void Visions::loadGoals() {
    qDebug() << "Entering loadGoals()...";

    // Clear and resize the list before loading
    goalDataList.clear();
    goalDataList.resize(MAX_GOAL_SLOTS);

    QSqlQuery query(db);
    query.prepare("SELECT goal_id, goal_name, required_amount, downpayment, time_limit "
                  "FROM goals WHERE user_id = :userId ORDER BY goal_name ASC");
    query.bindValue(":userId", currentUserId);

    if (!query.exec()) {
        qWarning() << "Failed to load goals:" << query.lastError().text();
        return;
    }

    // populate the goalDataList with the results
    int currentSlot = 0;
    while (query.next() && currentSlot < MAX_GOAL_SLOTS) {
        GoalData data;
        data.id = query.value("goal_id").toString();
        data.name = query.value("goal_name").toString();
        data.incomeRequired = query.value("required_amount").toDouble();
        data.downpayment = query.value("downpayment").toDouble();
        data.duration = query.value("time_limit").toInt();
        data.slotIndex = currentSlot + 1;
        goalDataList[currentSlot] = data;
        currentSlot++;
    }

    // Update the UI for all slots, whether they were populated or not
    for (int i = 0; i < MAX_GOAL_SLOTS; ++i) {
        updateGoalUI(i + 1, goalDataList[i]);
    }

    qDebug() << "Goals loaded and UI updated. Exiting loadGoals().";
}
void Visions::saveGoal(const GoalData &data) {
    qDebug() << "Entering saveGoal() for ID:" << data.id;

    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database not open for saving goal.");
        return;
    }

    //Attempt to UPDATE the existing record first
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE goals SET "
                        "goal_name = :goal_name, "
                        "required_amount = :required_amount, "
                        "downpayment = :downpayment, "
                        "time_limit = :time_limit "
                        "WHERE goal_id = :goal_id AND user_id = :user_id");

    updateQuery.bindValue(":goal_id", data.id);
    updateQuery.bindValue(":user_id", currentUserId);
    updateQuery.bindValue(":goal_name", data.name);
    updateQuery.bindValue(":required_amount", data.incomeRequired);
    updateQuery.bindValue(":downpayment", data.downpayment);
    updateQuery.bindValue(":time_limit", data.duration);

    if (!updateQuery.exec()) {
        qWarning() << "Failed to update goal:" << updateQuery.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to update existing goal.");
        return;
    }

    // Check if any rows were affected (meaning an update happened)
    if (updateQuery.numRowsAffected() > 0) {
        qDebug() << "Goal updated successfully for ID:" << data.id;
        loadGoals(); // Refresh the UI
        return;
    }

    // If no rows were affected by the update, it must be a new goal. So, INSERT it.
    QSqlQuery insertQuery(db);
    insertQuery.prepare("INSERT INTO goals "
                        "(goal_id, user_id, goal_name, required_amount, downpayment, time_limit) "
                        "VALUES (:goal_id, :user_id, :goal_name, :required_amount, :downpayment, :time_limit)");

    insertQuery.bindValue(":goal_id", data.id);
    insertQuery.bindValue(":user_id", currentUserId);
    insertQuery.bindValue(":goal_name", data.name);
    insertQuery.bindValue(":required_amount", data.incomeRequired);
    insertQuery.bindValue(":downpayment", data.downpayment);
    insertQuery.bindValue(":time_limit", data.duration);

    if (!insertQuery.exec()) {
        qWarning() << "Failed to insert new goal:" << insertQuery.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to insert new goal.");
    } else {
        qDebug() << "New goal inserted successfully for ID:" << data.id;
        loadGoals(); // Refresh the UI
    }
}

void Visions::deleteGoal(int goalIndex) {
    qDebug() << "DEBUG: Entering deleteGoal for goalIndex:" << goalIndex;

    if (!db.isOpen()) {
        qWarning() << "Database not open for deleting goal!";
        QMessageBox::critical(this, "Database Error", "Database not open for deleting goal.");
        return;
    }

    if (goalIndex < 1 || goalIndex > 6) {
        qWarning() << "Invalid goal index:" << goalIndex;
        return;
    }

    const int index = goalIndex - 1; // Convert to 0-based index for QList
    QString goalIdToDelete = goalDataList[index].id;

    if (goalIdToDelete.isEmpty()) {
        qDebug() << "DEBUG: No goal in slot" << goalIndex << "to delete. UI already clear or never had a goal.";
        updateGoalUI(goalIndex, GoalData()); // Ensure UI for this slot is cleared
        return;
    }

    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion",
                                  QString("Are you sure you want to delete the goal '%1'? This action cannot be undone.").arg(goalDataList[index].name),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        qDebug() << "DEBUG: Deletion cancelled by user for goal at index:" << goalIndex;
        return; // User cancelled, do nothing
    }

    qDebug() << "--- Deleting Goal from Slot:" << goalIndex << "---";

    // Delete from database
    QSqlQuery deleteQuery(db);
    deleteQuery.prepare("DELETE FROM goals WHERE goal_id = :id AND user_id = :userId");
    deleteQuery.bindValue(":id", goalIdToDelete);
    deleteQuery.bindValue(":userId", currentUserId);

    if (!deleteQuery.exec()) {
        qWarning() << "DEBUG: Failed to delete goal from DB:" << deleteQuery.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to delete goal from the database.");
    } else {
        qDebug() << "DEBUG: Goal" << goalIdToDelete << "deleted from DB successfully.";
        QMessageBox::information(this, "Goal Deleted", "Goal has been successfully deleted.");

        // Reset the GoalData object in memory to an empty state
        goalDataList[index] = GoalData();
        goalDataList[index].slotIndex = goalIndex; // Keep the correct slot index

        // After successful deletion, reload all goals to refresh the UI
        loadGoals();
    }
    qDebug() << "DEBUG: Exiting deleteGoal for goalIndex:" << goalIndex;
}


// UI Slot Handlers
void Visions::onAddButtonClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) {
        qWarning() << "onAddButtonClicked called by non-QPushButton sender!";
        return;
    }

    int identifiedSlotIndex_0_based = -1; // This will hold the 0-based index derived from the button
    QString specificGoalName = "";

    // Determine which "Add" button was clicked and assign the corresponding 0-based slot index and specific name
    if (clickedButton == ui->add) {
        identifiedSlotIndex_0_based = 0;
        specificGoalName = "🏡REAL ESTATE";
    } else if (clickedButton == ui->add_2) {
        identifiedSlotIndex_0_based = 1;
        specificGoalName = "🚗CAR";
    } else if (clickedButton == ui->add_3) {
        identifiedSlotIndex_0_based = 2;
        specificGoalName = "✈️VACATION";
    } else if (clickedButton == ui->add_4) {
        identifiedSlotIndex_0_based = 3;
        specificGoalName = "🎓EDUCATION";
    } else if (clickedButton == ui->add_5) {
        identifiedSlotIndex_0_based = 4;
        specificGoalName = "🌱PERSONAL GROWTH";
    } else if (clickedButton == ui->add_6) {
        identifiedSlotIndex_0_based = 5;
        specificGoalName ="🚨EMERGENCY FUND";
    } else {
        // Fallback for an unknown 'Add' button, though all 6 should be covered
        qWarning() << "Clicked Add button did not match a known slot. Attempting to find first available.";
        identifiedSlotIndex_0_based = findNextAvailableSlot() - 1; // Convert to 0-based
        if (identifiedSlotIndex_0_based == -1) {
            QMessageBox::information(this, "Limit Reached", "You have reached the maximum of 6 goals.");
            return;
        }
        specificGoalName = "New Goal " + QString::number(identifiedSlotIndex_0_based + 1); // Generic fallback name
    }

    // check if the determined slot is already occupied
    if (identifiedSlotIndex_0_based != -1 && !goalDataList[identifiedSlotIndex_0_based].isEmpty()) {
        QMessageBox::information(this, "Slot Taken", "This goal slot is already taken. Please use 'Edit' or 'Delete' if you wish to change this goal.");
        return;
    }
    if (identifiedSlotIndex_0_based == -1) {
        QMessageBox::information(this, "Limit Reached", "Could not find an empty goal slot.");
        return;
    }


    Insertt *dialog = new Insertt(this);
    dialog->setExistingGoals(goalDataList);

    // Create a GoalData object to pass.
    GoalData newGoalDefaults; // Declaration of GoalData object
    newGoalDefaults.name = specificGoalName;


    dialog->setGoalData(newGoalDefaults); // Pass the GoalData with the pre-set name
    // Connect the dialog's signal to handler in Visions
    // Pass the 1-based slot index to onGoalSet
    connect(dialog, &Insertt::goalSet, this, [this, slotIndex_1_based = identifiedSlotIndex_0_based + 1](const GoalData &data){
        onGoalSet(slotIndex_1_based, data);
    });

    // Show the dialog
    dialog->exec();

    // Clean up the dialog after it closes
    delete dialog;
}

// Generic edit goal function
void Visions::editGoal(int goalIndex) {
    if (goalIndex < 1 || goalIndex > 6) return;

    GoalData currentData = goalDataList[goalIndex - 1]; // Get the data for the selected slot
    if (currentData.isEmpty()) {
        QMessageBox::information(this, "No Goal", "There is no goal in this slot to edit. Use 'Add' instead.");
        return;
    }

    Insertt *dialog = new Insertt(this);
    dialog->setExistingGoals(goalDataList);
    dialog->setGoalData(currentData); // Pass existing data to the dialog for editing

    connect(dialog, &Insertt::goalSet, this, [this, goalIndex](const GoalData &newData){
        onGoalSet(goalIndex, newData); // When dialog returns, update this slot
    });
    int result = dialog->exec();
    qDebug() << "Dialog result: " << result;
    delete dialog;
}
// A generic slot to handle goal data from any button (Add or Edit)
void Visions::onGoalSet(int goalIndex, const GoalData &data) {
    if (goalIndex < 1 || goalIndex > 6) {
        qWarning() << "Invalid goal index passed to onGoalSet:" << goalIndex;
        return;
    }

    GoalData updatedData = data; // Get the data sent from the dialog

    // Check if the data from the dialog has an ID. If not, it's a new goal.
    if (updatedData.id.isEmpty()) {
        updatedData.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
    // If the ID is not empty, we assume it's an existing goal and use the ID from the dialog.

    updatedData.slotIndex = goalIndex; // Assign slot index for internal tracking

    // Update the in-memory list first
    goalDataList[goalIndex - 1] = updatedData;

    // Save/update to the database.
    // The saveGoal function will use the ID in updatedData to either INSERT or REPLACE.
    saveGoal(updatedData);
}

// UI Update Helpers
void Visions::updateGoalUI(int goalIndex, const GoalData &data)
{
    if (goalIndex < 1 || goalIndex > 6) {
        qWarning() << "Invalid goal index for updateGoalUI:" << goalIndex;
        return;
    }

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
        qWarning() << "Failed to get all UI elements for goal index:" << goalIndex;
        return;
    }

    if (data.isEmpty()) { // Display placeholder for empty slots
        stackedWidget->setCurrentIndex(0); // Show placeholder page
        progressBar->setVisible(false);
        // Ensure buttons are correctly visible/hidden for empty slots
        addButton->setVisible(true);
        editButton->setVisible(false);
        deleteButton->setVisible(false);

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
        // Ensure buttons are correctly visible/hidden for filled slots
        addButton->setVisible(false);
        editButton->setVisible(true);
        deleteButton->setVisible(true);
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


//Navigation methods
void Visions::on_toolButton_clicked()
{
    // Use the member variables already available in Visions for the current user's ID and Email
    profile *p = new profile(currentUserId, currentUserEmail, this);
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
