#include "Help.h"
#include "ui_Help.h"
#include "RecordWindow.h"
#include "visions.h"
#include "review.h"
#include "homewindow.h"
#include "analysiswindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QSizePolicy>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

// Member variables for user context
Help::Help(QString username, QString email, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help)
    , currentUserName(username)
    , currentUserEmail(email)
    , currentUserId(userId)
{
    ui->setupUi(this);

    // ✅ Persistent DB connection
    QString connectionName = "qt_sql_shared_connection";
    QSqlDatabase db;

    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
        db.setDatabaseName(dbPath);
        qDebug() << "Resolved DB Path in Help:" << dbPath;
    }

    if (!db.open()) {
        qDebug() << "❌ Failed to open database in Help:" << db.lastError().text();
        return;
    }

    // 🧭 Navigation setup
    QWidget *navContainer = new QWidget(this);
    navContainer->setStyleSheet("background-color: white;");
    navContainer->setFixedWidth(170);

    QVBoxLayout *navLayout = new QVBoxLayout(navContainer);
    navLayout->setContentsMargins(10, 20, 10, 10);
    navLayout->setSpacing(10);

    QFont navFont("Segoe UI", 10, QFont::Bold);

    QPushButton *dashboardBtn = new QPushButton("🏠 Home");
    QPushButton *recordBtn    = new QPushButton("➕ Add Record");
    QPushButton *analyticsBtn = new QPushButton("📈 Analytics");
    QPushButton *goalsBtn     = new QPushButton("🎯 Goals");
    QPushButton *reviewyBtn   = new QPushButton("📋 Review");
    QPushButton *helpBtn      = new QPushButton("❓ Help");

    QList<QPushButton*> buttons = { dashboardBtn, recordBtn, analyticsBtn, goalsBtn, reviewyBtn, helpBtn };

    for (auto btn : buttons) {
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setMinimumHeight(40);
        btn->setStyleSheet(
            "color: #2c3e50;"
            "background-color: #e0e0e0;"
            "border: none;"
            "padding: 8px;"
            );
        navLayout->addWidget(btn);
    }

    navLayout->addStretch();  // Push buttons to top

    // ✅ Connect navigation actions
    connect(dashboardBtn, &QPushButton::clicked, this, &Help::openHome);
    connect(recordBtn,    &QPushButton::clicked, this, &Help::openRecordWindow);
    connect(analyticsBtn, &QPushButton::clicked, this, &Help::openAnalytics);
    connect(goalsBtn,     &QPushButton::clicked, this, &Help::openvisions);
    connect(reviewyBtn,   &QPushButton::clicked, this, &Help::openreview);

    // Layout main content
    QWidget *mainWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QWidget *originalCentral = ui->centralwidget;
    ui->centralwidget->setParent(nullptr);

    mainLayout->addWidget(navContainer, 1);
    mainLayout->addWidget(originalCentral, 4);

    setCentralWidget(mainWidget);
}

Help::~Help() {
    delete ui;
}

// ✅ Navigation slot implementations
void Help::openHome() {
    home_window = new homeWindow(currentUserName, currentUserEmail, currentUserId, this);
    home_window->show();
    this->hide();
}

void Help::openRecordWindow() {
    RecordWindow *record_window = new RecordWindow(currentUserName, currentUserEmail, currentUserId, this);
    record_window->show();
    this->hide();
}

void Help::openAnalytics() {
    analysisWindow *analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
    this->hide();
}

void Help::openvisions() {
    Visions *vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
    vision_win->show();
    this->hide();
}

void Help::openreview() {
    review *review_win = new review(currentUserName, currentUserEmail, currentUserId, this);
    review_win->show();
    this->hide();
}
