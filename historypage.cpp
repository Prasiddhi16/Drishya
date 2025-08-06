#include "historypage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QSqlRecord>
#include <QCoreApplication>
#include <QHeaderView>

historypage::historypage(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background-color: #2C3E50;");

    // Setup DB connection
    QString connectionName = "qt_sql_history_connection";
    if (!QSqlDatabase::contains(connectionName)) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
        db.setDatabaseName(dbPath);

        if (!db.open()) {
            QMessageBox::critical(this, "Database Error", "Failed to open database.");
            return;
        }
    }

    startDateEdit = new QDateEdit(QDate::currentDate().addMonths(-1));
    startDateEdit->setDisplayFormat("yyyy/MM/dd");
    startDateEdit->setStyleSheet("color:white");
    startDateEdit->setCalendarPopup(true);

    endDateEdit = new QDateEdit(QDate::currentDate());
    endDateEdit->setDisplayFormat("yyyy/MM/dd");
    endDateEdit->setStyleSheet("color:white");
    endDateEdit->setCalendarPopup(true);

    viewHistoryButton = new QPushButton("View History");
    viewHistoryButton->setStyleSheet("background-color: #ADD8E6; color: black; border-radius: 5px; padding: 6px 12px;");

    model = new QSqlQueryModel(this);
    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setAlternatingRowColors(true);
    tableView->setStyleSheet("background-color: white; color: black; alternate-background-color: #F2F2F2;");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tableView->setFrameStyle(QFrame::NoFrame);

    // Filter layout
    QHBoxLayout *filterLayout = new QHBoxLayout;
    QLabel *fromLabel = new QLabel("From:");
    fromLabel->setStyleSheet("color: white;");
    filterLayout->addWidget(fromLabel);
    filterLayout->addWidget(startDateEdit);
    QLabel *toLabel = new QLabel("To:");
    toLabel->setStyleSheet("color: white;");
    filterLayout->addWidget(toLabel);
    filterLayout->addWidget(endDateEdit);
    filterLayout->addWidget(viewHistoryButton);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addLayout(filterLayout);
    mainLayout->addWidget(tableView);
    mainLayout->setStretch(0, 0);
    mainLayout->setStretch(1, 1);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    connect(viewHistoryButton, &QPushButton::clicked, this, &historypage::loadFilteredData);
    this->showMaximized();
}

historypage::~historypage() {}

void historypage::loadFilteredData()
{
    if (!startDateEdit || !endDateEdit) {
        qDebug() << "Date edits not initialized!";
        return;
    }

    if (startDateEdit->date() > endDateEdit->date()) {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowTitle("No Records");
        msgBox->setText("Start date cant be later than the end date.");
        msgBox->setStyleSheet(
            "QLabel { color: white; }"
            "QMessageBox { background-color: #2C3E50; }"
            "QPushButton { color: black; background-color: #ADD8E6; border-radius: 5px; padding: 6px 12px; }"
            );
        msgBox->exec();
        return;

    }

    QString startDate = startDateEdit->date().toString("yyyy-MM-dd");
    QString endDate = endDateEdit->date().toString("yyyy-MM-dd");

    QSqlDatabase db = QSqlDatabase::database("qt_sql_history_connection");
    QSqlQuery query(db);
    query.prepare("SELECT * FROM records WHERE user_id = :userId AND timestamp BETWEEN :start AND :end ORDER BY timestamp DESC");
    query.bindValue(":userId", currentUserId);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);

    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    model->setQuery(query); // ✅ No std::move

    // Hide unwanted columns
    int idColumn = model->record().indexOf("id");
    int userIdColumn = model->record().indexOf("user_id");
    int incomeCurrencyColumn = model->record().indexOf("income_currency");
    int expenseCurrencyColumn = model->record().indexOf("expense_currency");

    if (idColumn != -1) tableView->hideColumn(idColumn);
    if (userIdColumn != -1) tableView->hideColumn(userIdColumn);
    if (incomeCurrencyColumn != -1) tableView->hideColumn(incomeCurrencyColumn);
    if (expenseCurrencyColumn != -1) tableView->hideColumn(expenseCurrencyColumn);

    // Custom headers for visible columns
    model->setHeaderData(2, Qt::Horizontal, "Income");
    model->setHeaderData(3, Qt::Horizontal, "Income Category");
    model->setHeaderData(5, Qt::Horizontal, "Expense");
    model->setHeaderData(6, Qt::Horizontal, "Expense Category");
    model->setHeaderData(8, Qt::Horizontal, "Bill No/Id");
    model->setHeaderData(9, Qt::Horizontal, "Review");
    model->setHeaderData(10, Qt::Horizontal, "Time");

    if (model->rowCount() == 0) {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowTitle("No Records");
        msgBox->setText("No history found for the selected date range.");
        msgBox->setStyleSheet(
            "QLabel { color: white; }"
            "QMessageBox { background-color: #2C3E50; }"
            "QPushButton { color: black; background-color: #ADD8E6; border-radius: 5px; padding: 6px 12px; }"
            );
        msgBox->exec();

    }
}

void historypage::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
