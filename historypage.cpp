#include "historypage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QDebug>

historypage::historypage(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create widgets
    startDateEdit = new QDateEdit(QDate::currentDate().addMonths(-1));
    startDateEdit->setCalendarPopup(true);

    endDateEdit = new QDateEdit(QDate::currentDate());
    endDateEdit->setCalendarPopup(true);

    viewHistoryButton = new QPushButton("View History");

    model = new QSqlQueryModel(this);
    tableView = new QTableView(this);
    tableView->setModel(model);

    // Layout for filter controls
    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(new QLabel("From:"));
    filterLayout->addWidget(startDateEdit);
    filterLayout->addWidget(new QLabel("To:"));
    filterLayout->addWidget(endDateEdit);
    filterLayout->addWidget(viewHistoryButton);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addLayout(filterLayout);
    mainLayout->addWidget(tableView);

    // Connect button click to data loading slot
    connect(viewHistoryButton, &QPushButton::clicked, this, &historypage::loadFilteredData);

    // Load initial data
    loadFilteredData();
}

historypage::~historypage()
{
}

void historypage::loadFilteredData()
{
    QString startDate = startDateEdit->date().toString("yyyy-MM-dd");
    QString endDate = endDateEdit->date().toString("yyyy-MM-dd");

    QString queryStr = QString(
                           "SELECT id, category, amount, date FROM history "
                           "WHERE date BETWEEN '%1' AND '%2' "
                           "ORDER BY date DESC"
                           ).arg(startDate, endDate);

    model->setQuery(queryStr);

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Category");
    model->setHeaderData(2, Qt::Horizontal, "Amount");
    model->setHeaderData(3, Qt::Horizontal, "Date");

    tableView->resizeColumnsToContents();
}
