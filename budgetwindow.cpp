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

budgetWindow::budgetWindow (const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    ,currentUserEmail(userEmail),
    currentUserId(userId)

  , ui(new Ui::budgetWindow)
    , model(new QSqlQueryModel(this))

{
    ui->setupUi(this);

    QString connectionName = "qt_sql_budget_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/centralized.db");


    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        return;

    }

    QSqlQuery query(db);
    query.prepare("SELECT expense_amount, timestamp, expense_category FROM records WHERE user_id = :uid");
    query.bindValue(":uid", currentUserId);

    if (!query.exec()) {
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
