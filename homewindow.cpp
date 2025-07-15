#include "homewindow.h"
#include "ui_homewindow.h"
#include "analysiswindow.h"

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

homeWindow::homeWindow(const QString &userEmail, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homeWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #000000;"); // Entire app background

    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);


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


    QWidget *contentWidget = new QWidget;
    contentWidget->setStyleSheet("background-color: #131b39;");
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    QVBoxLayout *headerLayout = new QVBoxLayout;
    headerLayout->setSpacing(6); // Adjust this to control spacing

    QLabel *greeting = new QLabel("👋 Hello, " + currentUserEmail.section('@', 0, 0) + "!");
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

    // 💰 Income, Expenses, Savings Frames
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
    contentLayout->addStretch(); // Pushes chart to bottom


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
    QAreaSeries *areaExpense = new QAreaSeries(expenseSeries);
    QAreaSeries *areaSavings = new QAreaSeries(savingsSeries);

    areaIncome->setName("Income");
    areaIncome->setBrush(QColor(168, 218, 220, 160));
    areaExpense->setName("Expenses");
    areaExpense->setBrush(QColor(240, 128, 128, 160));
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
    chart->axes(Qt::Horizontal).first()->setTitleBrush(QBrush(Qt::black));
    chart->axes(Qt::Vertical).first()->setTitleText("Amount");
    chart->axes(Qt::Vertical).first()->setTitleBrush(QBrush(Qt::black));

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
}

void homeWindow::openAnalytics()
{
    analysisWindow *analysis_window = new analysisWindow(currentUserEmail, this);
    analysis_window->show();
}
