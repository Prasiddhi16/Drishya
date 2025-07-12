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

// Qt Charts headers
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
//QT_CHARTS_USE_NAMESPACE

homeWindow::homeWindow(const QString &userEmail, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homeWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);

    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // 🌐 Navigation Panel
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #F0F0F0;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(20);
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
        navLayout->addWidget(btn);
    }
    connect(buttons[2], &QPushButton::clicked, this, &homeWindow::openAnalytics);

    // 📦 Content Area
    QWidget *contentWidget = new QWidget;
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    QLabel *greeting = new QLabel("👋 Hello, " + currentUserEmail.section('@', 0, 0) + "!");
    QFont greetingFont("Segoe UI", 14, QFont::Bold);
    greeting->setFont(greetingFont);
    greeting->setStyleSheet("color: #222;");
    greeting->setAlignment(Qt::AlignLeft);

    contentLayout->addWidget(greeting);

    // 📊 Dashboard Info Frames
    QHBoxLayout *infoLayout = new QHBoxLayout;
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
        QLabel *amount = new QLabel("₹ --"); // Placeholder
        amount->setAlignment(Qt::AlignCenter);
        amount->setFont(QFont("Segoe UI", 12, QFont::Bold));
        frameLayout->addWidget(label);
        frameLayout->addWidget(amount);

        infoLayout->addWidget(infoFrame);
    }

    contentLayout->addLayout(infoLayout);

    // 🧁 Chart Placeholder (Pie-style)
    QPieSeries *series = new QPieSeries();
    series->append("Expenses", 65);
    series->append("Savings", 35);
    series->setHoleSize(0.25);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Preview Breakdown");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedHeight(250);
    chartView->setStyleSheet("background: transparent;");

    contentLayout->addWidget(chartView);
    contentLayout->addStretch();

    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(contentWidget);
    central->setLayout(mainLayout);
    setCentralWidget(central);
    resize(1000, 600);
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
