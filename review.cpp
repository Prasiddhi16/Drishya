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
#include "loginwindow.h"

#include "historypage.h"
#include "RecordWindow.h"
#include "visions.h"
#include "analysiswindow.h"
#include "homewindow.h"
#include "Help.h"
#include "expert.h"
#include "compare.h"
#include "graph.h"
#include "taxDialog.h"
#include "profile.h"

review::review(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId),
    ui(new Ui::review)
{
    ui->setupUi(this);
    this->showMaximized();

    QPixmap pix(":/img/img/profileicon.png");
    ui->toolButton->setIcon(QIcon(pix));
    ui->toolButton->setIconSize(ui->toolButton->size());

    QString connectionName = "qt_sql_rev_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    db.setDatabaseName(dbPath);

    qDebug() << "Review DB path resolved to:" << dbPath;

    if (!db.open()) {
        qDebug() << "DB Open Error:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to open database.");
        return;
    }

    QDate currentDate = QDate::currentDate();
    int currentMonth = currentDate.month();
    int currentYear = currentDate.year();

    double monthlyIncome = 0.0, monthlyExpense = 0.0;

    QSqlQuery query(db);
    query.prepare("SELECT income_amount, expense_amount, timestamp FROM records WHERE user_id = :userId");
    query.bindValue(":userId", currentUserId);

    if (!query.exec()) {
        qDebug() << "Query Error:" << query.lastError().text();
    } else {
        while (query.next()) {
            double income = query.value(0).toDouble();
            double expense = query.value(1).toDouble();
            QDateTime dt = QDateTime::fromString(query.value(2).toString(), "yyyy-MM-dd hh:mm:ss");
            QDate recordDate = dt.date();

            if (recordDate.month() == currentMonth && recordDate.year() == currentYear) {
                monthlyIncome += income;
                monthlyExpense += expense;
            }
        }
    }

    double monthlySavings = monthlyIncome - monthlyExpense;
    int expensePercent = (monthlyIncome > 0) ? static_cast<int>((monthlyExpense / monthlyIncome) * 100) : 0;
    int savingsPercent = 100 - expensePercent;

    QString progressStyle = R"(
    QProgressBar {
        border: 2px solid #cfcfcf;
        border-radius: 8px;
        text-align: center;
        height: 20px;
        color: white;
    }
    QProgressBar::chunk {
        background-color:#B7B7B7;
        width: 10px;
    }
)";

    ui->progressExpenseBar->setStyleSheet(progressStyle);
    ui->progressSavingsBar->setStyleSheet(progressStyle);

    ui->progressExpenseBar->setMinimum(0);
    ui->progressExpenseBar->setMaximum(100);
    ui->progressExpenseBar->setValue(expensePercent);

    ui->progressSavingsBar->setMinimum(0);
    ui->progressSavingsBar->setMaximum(100);
    ui->progressSavingsBar->setValue(savingsPercent);

    ui->labelSavings->setText(" 🏦 Savings this month: Rs. " + QString::number(monthlySavings,'f',2));
    ui->labelExpense->setText(" 💵 Expense this month: Rs. " + QString::number(monthlyExpense,'f',2));

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
    connect(buttons[5], &QPushButton::clicked, this, &review::openhelp);

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

void review::closeEvent(QCloseEvent *event)
{
    home_window = new homeWindow(currentUserName, currentUserEmail, currentUserId, nullptr);
    home_window->show();
    event->accept();
}

void review::on_btnCompare_clicked()
{
    Compare = new compare(currentUserEmail, currentUserId, this);
    connect(Compare, &compare::windowClosed, this, &review::showMaximized);
    this->hide();
    Compare->show();
}

void review::on_btnExper_clicked()
{
    Expert = new expert(currentUserEmail, currentUserId, this);
    connect(Expert, &expert::windowClosed, this, &review::showMaximized);
    this->hide();
    Expert->show();
}

void review::on_btnExpense_clicked()
{
    Graph = new graph(currentUserEmail, currentUserId, this);
    Graph->show();
}

void review::on_btnTax_clicked()
{
    Taxdialog = new taxDialog(currentUserEmail, currentUserId, this);
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
    Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId,this);
    vision_win->show();
    this->hide();
}

void review::openAnalytics()
{
    analysisWindow* analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
    this->hide();
}

void review::on_toolButton_clicked()
{
    profile *p = new profile(currentUserId, currentUserEmail, this);
    p->setWindowFlags(Qt::Popup);
    QPoint globalPos = ui->toolButton->mapToGlobal(QPoint(0,ui->toolButton->height()));
    p->move(globalPos);
    p->show();
}

void review::openhelp()
{
    Help *help_win = new Help(currentUserName, currentUserEmail, currentUserId, this);
    help_win->show();
    this->hide();
}

void review::on_pushButton_clicked()
{
    History = new historypage(currentUserName, currentUserEmail, currentUserId, this);
    connect(History, &historypage::windowClosed, this, &review::showMaximized);
    History->show();
    this->hide();
}
