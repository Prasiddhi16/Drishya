#include "homewindow.h"
#include "ui_homewindow.h"
#include "analysiswindow.h"
#include "loginwindow.h"
#include "RecordWindow.h"
#include "visions.h"
#include "review.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>
#include <QDebug>
#include <QPainter>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// Qt Charts (Bar Chart)
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

homeWindow::homeWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::homeWindow),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId),
    login_window(nullptr)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #000000;");
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // Navigation Panel
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Segoe UI", 10, QFont::Bold);
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
    }
    connect(buttons[1], &QPushButton::clicked, this, &homeWindow::openRecordWindow);
    connect(buttons[2], &QPushButton::clicked, this, &homeWindow::openAnalytics);
    connect(buttons[3], &QPushButton::clicked, this, &homeWindow::openvisions);
    connect(buttons[4], &QPushButton::clicked, this, &homeWindow::openreview);
    connect(buttons[5], &QPushButton::clicked, this, &homeWindow::logoutAndResetSession);

    // Content
    QWidget *contentWidget = new QWidget;
    contentWidget->setStyleSheet("background-color: #131b39;");
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    // Header
    QVBoxLayout *headerLayout = new QVBoxLayout;
    headerLayout->addSpacing(1);
    QLabel *greeting = new QLabel("👋 Hello, " + currentUserName + "!");
    greeting->setFont(QFont("Segoe UI", 13, QFont::Bold));
    greeting->setStyleSheet("color: #FFFFFF;");
    greeting->setAlignment(Qt::AlignLeft);
    QLabel *motivationLabel = new QLabel("💡 Finance Tip: Tracking even small expenses can reveal big savings opportunities!");
    motivationLabel->setFont(QFont("Segoe UI", 11, QFont::Bold));
    motivationLabel->setStyleSheet("color: #98FF98;");
    motivationLabel->setAlignment(Qt::AlignLeft);
    headerLayout->addWidget(greeting);
    headerLayout->setSpacing(0);
    headerLayout->addWidget(motivationLabel);
    contentLayout->addLayout(headerLayout);
    contentLayout->addSpacing(20);

    // Summary Row
    QHBoxLayout *summaryRowLayout = new QHBoxLayout;
    summaryRowLayout->setSpacing(20);

    // Budget Overview Frame
    QFrame *budgetFrame = new QFrame;
    budgetFrame->setStyleSheet("background-color: #E6E6FA; border-radius: 8px;");
    budgetFrame->setFixedSize(180, 100);
    QVBoxLayout *budgetLayout = new QVBoxLayout(budgetFrame);
    QLabel *budgetLabel = new QLabel("📝 Budget Overview");
    budgetLabel->setFont(QFont("Segoe UI", 11, QFont::Bold));
    budgetLabel->setStyleSheet("color: #2c3e50;");
    budgetLabel->setAlignment(Qt::AlignCenter);
    budgetAmount = new QLabel("₹ --");
    budgetAmount->setFont(QFont("Segoe UI", 13, QFont::Bold));
    budgetAmount->setStyleSheet("color: #1abc9c;");
    budgetAmount->setAlignment(Qt::AlignCenter);
    budgetLayout->addWidget(budgetLabel);
    budgetLayout->addWidget(budgetAmount);
    summaryRowLayout->addWidget(budgetFrame);

    // Financial Frames
    QStringList frameLabels = {"💰 Total Income", "💸 Total Expenses", "💾 Savings"};
    QStringList colors = {"#a8dadc", "#f08080", "#90ee90"};

    for (int i = 0; i < 3; ++i) {
        QFrame *infoFrame = new QFrame;
        infoFrame->setStyleSheet("background-color: " + colors[i] + "; border-radius: 8px;");
        infoFrame->setFixedSize(180, 100);
        QVBoxLayout *frameLayout = new QVBoxLayout(infoFrame);
        QLabel *label = new QLabel(frameLabels[i]);
        label->setAlignment(Qt::AlignCenter);
        label->setFont(QFont("Segoe UI", 11, QFont::Bold));

        QLabel *amount = new QLabel("₹ --");
        amount->setAlignment(Qt::AlignCenter);
        amount->setFont(QFont("Segoe UI", 12, QFont::Bold));

        if (i == 0) incomeAmount = amount;
        else if (i == 1) expenseAmount = amount;
        else savingsAmount = amount;

        frameLayout->addWidget(label);
        frameLayout->addWidget(amount);
        summaryRowLayout->addWidget(infoFrame);
    }

    contentLayout->addLayout(summaryRowLayout);

    // Database Access
    QString connectionName = "qt_sql_home_connection";
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase::removeDatabase(connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/centralized.db");
    QSqlQuery query(db);
    if (db.open()) {
        QSqlQuery query(db);
        double totalIncome = 0.0;
        double totalExpense = 0.0;

        query.prepare("SELECT SUM(income_amount) FROM records WHERE user_id = :uid");
        query.bindValue(":uid", currentUserId);
        if (query.exec() && query.next())
            totalIncome = query.value(0).toDouble();

        query.prepare("SELECT SUM(expense_amount) FROM records WHERE user_id = :uid");
        query.bindValue(":uid", currentUserId);
        if (query.exec() && query.next())
            totalExpense = query.value(0).toDouble();

        incomeAmount->setText("₹ " + QString::number(totalIncome, 'f', 2));
        expenseAmount->setText("₹ " + QString::number(totalExpense, 'f', 2));
        savingsAmount->setText("₹ " + QString::number(totalIncome - totalExpense, 'f', 2));
        budgetAmount->setText("₹ " + QString::number(totalIncome * 0.7, 'f', 2)); // 70% spending guideline
    } else {
        qDebug() << "DB Connection Failed:" << db.lastError().text();
    }



    QMap<int, double> incomeMap, expenseMap;


    query.prepare("SELECT strftime('%m', timestamp) AS month, SUM(income_amount) FROM records WHERE user_id = :uid GROUP BY month");
    query.bindValue(":uid", currentUserId);
    if (query.exec()) {
        while (query.next()) {
            int month = query.value(0).toInt();
            double income = query.value(1).toDouble();
            incomeMap[month] = income;
        }
    } else {
        qDebug() << "Income month query failed:" << query.lastError();
    }

    query.prepare("SELECT strftime('%m', timestamp) AS month, SUM(expense_amount) FROM records WHERE user_id = :uid GROUP BY month");
    query.bindValue(":uid", currentUserId);
    if (query.exec()) {
        while (query.next()) {
            int month = query.value(0).toInt();
            double expense = query.value(1).toDouble();
            expenseMap[month] = expense;
        }
    } else {
        qDebug() << "Expense month query failed:" << query.lastError();


    }

    // ---------------- Bar Chart Construction ----------------
    QBarSet *incomeSet  = new QBarSet("Income");
    QBarSet *expenseSet = new QBarSet("Expenses");
    QBarSet *savingsSet = new QBarSet("Savings");

    double minVal = 0.0; // allow negative savings
    double maxVal = 0.0;

    for (int month = 1; month <= 12; ++month) {
        double income  = incomeMap.value(month, 0.0);
        double expense = expenseMap.value(month, 0.0);
        double savings = income - expense; // may be negative

        *incomeSet  << income;
        *expenseSet << expense;
        *savingsSet << savings;

        if (income  > maxVal) maxVal = income;
        if (expense > maxVal) maxVal = expense;
        if (savings > maxVal) maxVal = savings;
        if (savings < minVal) minVal = savings; // track negative only
    }

    // Optional custom colors
    incomeSet->setColor(QColor("#3498db"));  // Blue
    expenseSet->setColor(QColor("#e74c3c")); // Red
    savingsSet->setColor(QColor("#2ecc71")); // Green

    QBarSeries *series = new QBarSeries();
    series->append(incomeSet);
    series->append(expenseSet);
    series->append(savingsSet);
   // series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("📊 Financial Overview");
    chart->setBackgroundBrush(QBrush(QColor("#ffffff")));
    chart->setTitleBrush(QBrush(Qt::black));
    chart->legend()->setLabelBrush(QBrush(Qt::black));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // X-axis: Months
    QStringList categories = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Month");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);



    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Amount (₹)");
    axisY->setRange(0, 50000);
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedHeight(300);
    chartView->setStyleSheet("background: transparent;");

    contentLayout->addSpacing(50);
    contentLayout->addWidget(chartView);
    contentLayout->setAlignment(chartView, Qt::AlignBottom);

    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(contentWidget);
    central->setLayout(mainLayout);
    setCentralWidget(central);
    resize(1000, 600);
    this->showMaximized();
}

homeWindow::~homeWindow()
{
    delete ui;
    if (login_window) {
        delete login_window;
        login_window = nullptr;
    }
}

void homeWindow::openAnalytics()
{
    analysisWindow *analysis_window = new analysisWindow(currentUserName, currentUserEmail, currentUserId, this);
    analysis_window->show();
}

void homeWindow::logoutAndResetSession()
{
    qDebug() << "Logging out via Help button";
    QSettings settings("YourOrganization", "YourApp");
    settings.setValue("keepMeLoggedIn", 0);

    login_window = new loginWindow();
    login_window->show();
    this->close();
}

void homeWindow::openRecordWindow()
{
    RecordWindow* record_window = new RecordWindow(currentUserName, currentUserEmail, currentUserId, this);
    record_window->show();
}

void homeWindow::openvisions()
{
    Visions* vision_win = new Visions(currentUserName, currentUserEmail, currentUserId, this);
    vision_win->show();
}

void homeWindow::openreview()
{
    review *review_win = new review(currentUserName, currentUserEmail, currentUserId, this);
    review_win->show();
}
