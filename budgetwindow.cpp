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

budgetWindow::budgetWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::budgetWindow)
    , model(new QSqlQueryModel(this))
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);

    QString connectionName = "qt_sql_budget_connection";

    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
        db.setDatabaseName(dbPath);
        qDebug() << "Resolved DB Path in budgetWindow:" << dbPath;

        if (!db.open()) {
            qDebug() << " DB Open Error:" << db.lastError().text();
            return;
        }
    }

    // Calculate the date of Monday of the current week (SQLite: 0=Sunday,...)
    // We'll use a WHERE clause to only fetch records >= Monday this week and < next Monday

    // Prepare the SQL query with date filters:
    QString sql = R"(
        SELECT expense_amount, timestamp, expense_category
        FROM records
        WHERE
          expense_amount > 0
          AND date(timestamp) >= date('now', 'weekday 1', '-7 days')  -- Monday of this week
          AND date(timestamp) < date('now', 'weekday 1')              -- Next Monday (exclusive)
        ORDER BY timestamp DESC
    )";

    QSqlQuery query(db);
    if (!query.exec(sql)) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Model error:" << model->lastError().text();
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, "Amount ₹");
    model->setHeaderData(1, Qt::Horizontal, "Date & Time");
    model->setHeaderData(2, Qt::Horizontal, "Category");

    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Debug print loaded data
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString value = model->data(model->index(row, col)).toString();
            qDebug() << "Row" << row << ", Col" << col << ": " << value;
        }
    }

    ui->tableView->show();
    this->showMaximized();
}

budgetWindow::~budgetWindow()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void budgetWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
