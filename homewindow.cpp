#include "homewindow.h"
#include "ui_homewindow.h"
#include "analysiswindow.h"
#include "loginwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>
#include <QDebug>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QSettings>

homeWindow::homeWindow(const QString &userName, const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::homeWindow),
    currentUserName(userName),
    currentUserEmail(userEmail),
    currentUserId(userId),
    login_window(nullptr) // Initialize pointer to null
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

    connect(buttons[2], &QPushButton::clicked, this, &homeWindow::openAnalytics);
    connect(buttons[5], &QPushButton::clicked, this, &homeWindow::logoutAndResetSession); // Secret logout

    // Content Widget and rest of layout
    QWidget *contentWidget = new QWidget;
    contentWidget->setStyleSheet("background-color: #131b39;");
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    QVBoxLayout *headerLayout = new QVBoxLayout;
    headerLayout->setSpacing(6);
    QLabel *greeting = new QLabel("👋 Hello, " + currentUserName + "!");
    greeting->setFont(QFont("Segoe UI", 13, QFont::Bold));
    greeting->setStyleSheet("color: #FFFFFF;");
    greeting->setAlignment(Qt::AlignLeft);
    QLabel *motivationLabel = new QLabel("💡 Finance Tip: Tracking even small expenses can reveal big savings opportunities!");
    motivationLabel->setFont(QFont("Segoe UI", 11, QFont::Bold));
    motivationLabel->setStyleSheet("color: #98FF98;");
    motivationLabel->setAlignment(Qt::AlignLeft);
    headerLayout->addWidget(greeting);
    headerLayout->addWidget(motivationLabel);
    contentLayout->addLayout(headerLayout);
    contentLayout->addSpacing(20);

    QHBoxLayout *summaryRowLayout = new QHBoxLayout;
    summaryRowLayout->setSpacing(20);
    QFrame *budgetFrame = new QFrame;
    budgetFrame->setStyleSheet("background-color: #E6E6FA; border-radius: 8px;");
    budgetFrame->setFixedSize(180, 100);
    QVBoxLayout *budgetLayout = new QVBoxLayout(budgetFrame);
    QLabel *budgetLabel = new QLabel("📝 Budget Overview");
    budgetLabel->setFont(QFont("Segoe UI", 11, QFont::Bold));
    budgetLabel->setStyleSheet("color: #2c3e50;");
    budgetLabel->setAlignment(Qt::AlignCenter);
    QLabel *budgetAmount = new QLabel("₹ --");
    budgetAmount->setFont(QFont("Segoe UI", 13, QFont::Bold));
    budgetAmount->setStyleSheet("color: #1abc9c;");
    budgetAmount->setAlignment(Qt::AlignCenter);
    budgetLayout->addWidget(budgetLabel);
    budgetLayout->addWidget(budgetAmount);
    summaryRowLayout->addWidget(budgetFrame);

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
        frameLayout->addWidget(label);
        frameLayout->addWidget(amount);
        summaryRowLayout->addWidget(infoFrame);
    }

    contentLayout->addLayout(summaryRowLayout);
    contentLayout->addStretch();

    // Chart setup
    QLineSeries *incomeSeries = new QLineSeries();
    incomeSeries->append(0, 2000);
    incomeSeries->append(1, 2500);
    incomeSeries->append(2, 2700);
    QLineSeries *expenseSeries = new QLineSeries();
    expenseSeries->append(0, 1500);
    expenseSeries->append(1, 1800);
    expenseSeries->append(2, 1600);
    QLineSeries *savingsSeries = new QLineSeries();
    savingsSeries->append(0, 500);
    savingsSeries->append(1, 700);
    savingsSeries->append(2, 1100);
    QAreaSeries *areaIncome = new QAreaSeries(incomeSeries);
    areaIncome->setName("Income");
    areaIncome->setBrush(QColor(168, 218, 220, 160));
    QAreaSeries *areaExpense = new QAreaSeries(expenseSeries);
    areaExpense->setName("Expenses");
    areaExpense->setBrush(QColor(240, 128, 128, 160));
    QAreaSeries *areaSavings = new QAreaSeries(savingsSeries);
    areaSavings->setName("Savings");
    areaSavings->setBrush(QColor(144, 238, 144, 160));

    QChart *chart = new QChart();
    chart->addSeries(areaIncome);
    chart->addSeries(areaExpense);
    chart->addSeries(areaSavings);
    chart->setTitle("📊 Financial Overview");
    chart->setBackgroundBrush(QBrush(QColor("#ffffff")));
    chart->setTitleBrush(QBrush(Qt::black));
    chart->legend()->setLabelBrush(QBrush(Qt::black));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setTitleText("Time");
    chart->axes(Qt::Vertical).first()->setTitleText("Amount");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedHeight(300);
    chartView->setStyleSheet("background: transparent;");
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
