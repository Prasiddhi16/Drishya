#include "analysiswindow.h"
#include "ui_analysiswindow.h"
#include "homewindow.h"
#include "budgetwindow.h"
#include "revwindow.h"
#include "weeklywindow.h"
#include "monthlywindow.h"
#include "RecordWindow.h"
#include "visions.h"
#include "review.h"
#include "Help.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>
#include <QTimer>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

analysisWindow::analysisWindow(QString username, QString email, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::analysisWindow)
    , currentUserName(username)
    , currentUserEmail(email)
    , currentUserId(userId)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #000000;"); // Dark background
    // ✅ Ensure persistent database connection
    QString connectionName = "qt_sql_shared_connection";
    QSqlDatabase db;

    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);

        // ✅ Use relative path to db file
        QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
        db.setDatabaseName(dbPath);

        qDebug() << "Resolved DB Path in analysisWindow:" << dbPath;
    }

    if (!db.open()) {
        qDebug() << "❌ Failed to open database in analysisWindow:" << db.lastError().text();
        return;
    }


    // 👋 Greeting
    ui->label_2->setText("👋 Hello, " + currentUserName + "!\nThis is what is going on with your finances:");
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setStyleSheet("font-size: 20px; color: #98FF98; font-weight: bold;");

    // 🧭 Navigation panel
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Segoe UI", 10, QFont::Bold);
    QStringList labels = { "🏠 Home", "➕ Add Record", "📈 Analytics", "🎯 Goals", "📋 Review", "❓ Help" };
    QList<QPushButton*> buttons;
    for (const QString &label : labels) {
        QPushButton *btn = new QPushButton(label);
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setMinimumHeight(20);
        btn->setStyleSheet("color: #2c3e50; background-color: #e0e0e0; border: none; border-radius: 0px; padding: 8px;");
        navLayout->addWidget(btn);
        buttons.append(btn);
    }

    connect(buttons[0], &QPushButton::clicked, this, &analysisWindow::openHome);
    connect(buttons[1], &QPushButton::clicked, this, &analysisWindow::openRecordWindow);
    connect(buttons[3], &QPushButton::clicked, this, &analysisWindow::openvisions);
    connect(buttons[4], &QPushButton::clicked, this, &analysisWindow::openreview);
    connect(buttons[5], &QPushButton::clicked, this, &analysisWindow::openhelp);
    // 🧱 Layout setup
    QWidget *centralWidget = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget);
    setCentralWidget(centralWidget);
    this->showMaximized();

    // 🔄 Start expense auto-update
    QTimer *expenseTimer = new QTimer(this);
    connect(expenseTimer, &QTimer::timeout, this, &analysisWindow::updateWeeklyExpense);
    expenseTimer->start(5000);
qDebug() << "analysisWindow initialized with userId:" << currentUserId;    // refresh every 5 seconds
    updateWeeklyExpense(); // Initial call

    // 📊 Percentage comparison
    double thisWeekTotal = 0.0, lastWeekTotal = 0.0;
    QSqlQuery totalQuery(db);
    totalQuery.prepare("SELECT SUM(expense_amount) FROM records WHERE user_id = :uid AND DATE(timestamp) >= DATE('now', 'weekday 0', '-6 days')");
    totalQuery.bindValue(":uid", currentUserId);
    totalQuery.exec();
    if (totalQuery.next()) thisWeekTotal = totalQuery.value(0).toDouble();

    totalQuery.prepare("SELECT SUM(expense_amount) FROM records WHERE user_id = :uid AND DATE(timestamp) BETWEEN DATE('now', 'weekday 0', '-13 days') AND DATE('now', 'weekday 0', '-7 days')");
    totalQuery.bindValue(":uid", currentUserId);
    totalQuery.exec();
    if (totalQuery.next()) lastWeekTotal = totalQuery.value(0).toDouble();


    double percentChange = (lastWeekTotal != 0.0) ? ((thisWeekTotal - lastWeekTotal) / lastWeekTotal) * 100.0 : 0.0;
    QString arrow = percentChange > 0 ? "↑" : percentChange < 0 ? "↓" : "→";double displayPercent = qMin(qAbs(percentChange), 100.0);
    QString labelText = QString("%1 %2%").arg(arrow).arg(displayPercent, 0, 'f', 2);
    QString color = percentChange > 0 ? "#ffbbbb" : percentChange < 0 ? "#cceecc" : "#f0f0f0";

    ui->percentage_label->setText(labelText);
    ui->percentage_label->setStyleSheet(QString("background-color: %1; border-radius: 8px; padding: 4px;").arg(color));
}

analysisWindow::~analysisWindow()
{
    delete ui;
}

void analysisWindow::updateWeeklyExpense()
{QSqlQuery query(QSqlDatabase::database("qt_sql_shared_connection"));

    qDebug() << "updateWeeklyExpense() using userId:" << currentUserId;
    QDate today = QDate::currentDate();
    QDate startOfWeek = today.addDays(-today.dayOfWeek() + 1); // Monday-start


    query.prepare("SELECT IFNULL(SUM(expense_amount), 0) FROM records "
                  "WHERE user_id= :uid AND date(timestamp) >= :start AND date(timestamp) <= :today");
    query.bindValue(":uid", currentUserId);
    query.bindValue(":start", startOfWeek.toString("yyyy-MM-dd"));
    query.bindValue(":today", today.toString("yyyy-MM-dd"));

    double weeklyExpense = 0.0;
    if (query.exec() && query.next()) {
        weeklyExpense = query.value(0).toDouble();
    } else {
        qDebug() << "SQL Error (weeklyExpense):" << query.lastError().text();
    }

    ui->expense_label->setText(" Weekly Expense: Rs " + QString::number(weeklyExpense));
    ui->expense_label->setStyleSheet("font-size: 20px; font-weight: bold; color: #ffffff;");
}

void analysisWindow::on_pushButton_clicked()
{
    this->hide();
    budget_window = new budgetWindow(currentUserEmail,currentUserId, this);
    connect(budget_window, &budgetWindow::windowClosed, this, &analysisWindow::show);
    budget_window->showMaximized();
}

void analysisWindow::on_pushButton_2_clicked()
{
    this->hide();
    rev_window = new revWindow(currentUserEmail, currentUserId,this);
    connect(rev_window, &revWindow::windowClosed, this, &analysisWindow::show);
    rev_window->showMaximized();
}

void analysisWindow::on_pushButton_3_clicked()
{
    this->hide();
    weekly_window = new weeklyWindow(currentUserEmail,currentUserId, this);
    connect(weekly_window, &weeklyWindow::windowClosed, this, &analysisWindow::show);
    weekly_window->showMaximized();
}

void analysisWindow::on_pushButton_4_clicked()
{
    this->hide();
    monthly_window = new monthlyWindow(currentUserEmail,currentUserId, this);
    connect(monthly_window, &monthlyWindow::windowClosed, this, &analysisWindow::show);
    monthly_window->showMaximized();
}

void analysisWindow::openHome()
{
    home_window = new homeWindow(currentUserName,currentUserEmail, currentUserId, this);
    home_window->show();
    this->hide();
}

void analysisWindow::openRecordWindow()
{
    RecordWindow* record_window = new RecordWindow(currentUserName, currentUserEmail, currentUserId, this);
    connect(record_window, &RecordWindow::expenseAdded, this, &analysisWindow::updateWeeklyExpense);
    record_window->show();
    this->hide();
}

void analysisWindow::openvisions()
{
    Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
    vision_win->show();
    this->hide();
}

void analysisWindow::openreview()
{
    review *review_win=new review(currentUserName, currentUserEmail, currentUserId, this);
    review_win->show();
    this->hide();
}
void analysisWindow::openhelp()
{
     Help *help_win =new Help(currentUserName, currentUserEmail, currentUserId, this);
    help_win->show();
}
