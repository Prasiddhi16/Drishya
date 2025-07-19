#include "review.h"
#include "ui_review.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QFrame>
#include <QSizePolicy>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

#include "historypage.h"
#include "RecordWindow.h"
#include "visions.h"
#include "analysiswindow.h"
#include "homewindow.h"


review::review(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId),
    ui(new Ui::review)
{
    ui->setupUi(this);
    this->showMaximized();

    QString connectionName = "qt_sql_rev_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);

    // Use relative path for DB - adjust path according to your project structure
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qDebug() << "Review DB path resolved to:" << dbPath;

    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to open database.");
        return;  // Important to stop constructor if DB doesn't open
    }

    // Navigation panel
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");

    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Arial", 10, QFont::Bold);

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
        btn->setFixedHeight(40);
    }

    connect(buttons[0], &QPushButton::clicked, this, &review::openHome);
    connect(buttons[1], &QPushButton::clicked, this, &review::openRecordWindow);
    connect(buttons[2], &QPushButton::clicked, this, &review::openAnalytics);
    connect(buttons[3], &QPushButton::clicked, this, &review::openvisions);
    //connect(buttons[4], &QPushButton::clicked, this, &review::openreview);
    //connect(buttons[5], &QPushButton::clicked, this, &homeWindow::logoutAndResetSession);

    QWidget *mainContainer = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(mainContainer);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget);

    this->setCentralWidget(mainContainer);
}

review::~review()
{
    delete ui;
}

void review::on_btnCompare_clicked()
{
    hide();
    Compare = new compare(this);
    Compare->show();
}

void review::on_btnExper_clicked()
{
    hide();
    Expert = new expert(this);
    Expert->show();
}

void review::on_btnExpense_clicked()
{
    Graph = new graph(this);
    Graph->show();
}

void review::on_btnTax_clicked()
{
    Taxdialog = new taxDialog(this);
    Taxdialog->show();
}

void review::openHome()
{
    home_window = new homeWindow(currentUserName, currentUserEmail, currentUserId, this);
    home_window->show();
    this->hide();
}

void review::openRecordWindow()
{
    RecordWindow* record_window = new RecordWindow(currentUserName, currentUserEmail, currentUserId, this);
    record_window->show();
    this->hide();
}

void review::openvisions()
{
    Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
    vision_win->show();
    this->hide();
}

void review::openAnalytics()
{
    analysisWindow* analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
    this->hide();
}
