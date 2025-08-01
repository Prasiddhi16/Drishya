#include "budgetwindow.h"
#include "ui_budgetwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QDebug>
#include <QCloseEvent>
#include <QCoreApplication>
#include <QDir>
#include <QTimer>

budgetWindow::budgetWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    currentUserEmail(userEmail),
    currentUserId(userId),
    ui(new Ui::budgetWindow),
    model(new QSqlQueryModel(this)),
    refreshTimer(new QTimer(this))
{
    ui->setupUi(this);

    QString connectionName = "qt_sql_budget_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);

    // Use relative path to the DB file
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qDebug() << "Resolved DB Path in budgetWindow:" << dbPath;

    if (!db.open()) {
        qDebug() << " DB Open Error:" << db.lastError().text();
        return;
    }

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet(R"(
    QTableView {
        border: 1px solid #5D6D7E;
        gridline-color: #5D6D7E;
        background-color: #FBFCFC;
        font-size: 14px;
    }

    QHeaderView::section {
        font-weight: bold;
        background-color: #F2F3F4;
        color: #2C3E50;
        border: 1px solid #5D6D7E;
        padding: 4px;
    }
)");
    ui->tableView->setSortingEnabled(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Trigger initial query
    refreshBudgetData();

    // Setup timer to refresh every 10 seconds
    connect(refreshTimer, &QTimer::timeout, this, &budgetWindow::refreshBudgetData);
    refreshTimer->start(10000); // 10 seconds

    ui->tableView->show();
    this->showMaximized();
}

budgetWindow::~budgetWindow()
{
    QSqlDatabase db = QSqlDatabase::database("qt_sql_budget_connection");
    if (db.isOpen()) {
        db.close();
    }

    delete ui;
}

void budgetWindow::refreshBudgetData()
{
    QString connectionName = "qt_sql_budget_connection";
    QSqlDatabase db = QSqlDatabase::database(connectionName);

    QSqlQuery query(db);
    query.prepare(R"(
    SELECT '₹ ' || printf("%.2f", expense_amount) AS formatted_amount,
           timestamp,
           expense_category
    FROM records
    WHERE user_id = :uid
      AND expense_amount > 0
      AND strftime('%W', timestamp) = strftime('%W', 'now')
      AND strftime('%Y', timestamp) = strftime('%Y', 'now')
)");

    query.bindValue(":uid", currentUserId);

    if (!query.exec()) {
        qDebug() << " Refresh query failed:" << query.lastError().text();
        return;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "Amount ₹");
    model->setHeaderData(1, Qt::Horizontal, "Date & Time");
    model->setHeaderData(2, Qt::Horizontal, "Category");

    if (model->lastError().isValid()) {
        qDebug() << " Model refresh error:" << model->lastError().text();
    }
}

void budgetWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
