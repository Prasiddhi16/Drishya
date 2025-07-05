#include "budgetwindow.h"
#include "ui_budgetwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QDebug>
#include <QCloseEvent>

budgetWindow::budgetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::budgetWindow)
    , model(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // Safely manage duplicate connection
    QString connectionName = "qt_sql_budget_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/MYFINANCERECORD/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/FINANCERECORD.db");

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return;
    }

    // Load fresh query
    QSqlQuery query(db);
    if (!query.exec("SELECT amount, date, expense_category FROM readable_expenses")) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << " Model error:" << model->lastError().text();
        return;
    }

    // 🏷️ Rename headers
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
