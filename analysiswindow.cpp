#include "analysiswindow.h"
#include "ui_analysiswindow.h"
#include "homewindow.h"
#include "budgetwindow.h"
#include "revwindow.h"
#include "weeklywindow.h"
#include "monthlywindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QFont>
#include <QSizePolicy>
analysisWindow::analysisWindow(const QString &userEmail, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::analysisWindow)
    , currentUserEmail(userEmail)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #000000;"); // Dark app background

    // 👋 Greeting label customization
    ui->label_2->setText("👋 Hello, " + currentUserEmail.section('@', 0, 0) + "!\nThis is what is going on with your finances:");
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setStyleSheet("font-size: 20px; color: #98FF98; font-weight: bold;");

    // 🧱 Navigation Panel (same style as homeWindow)
    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Segoe UI", 10, QFont::Bold);

    QPushButton *dashboardBtn = new QPushButton("🏠 Home");
    QPushButton *recordBtn    = new QPushButton("📊 Add Record");
    QPushButton *analyticsBtn = new QPushButton("📝 Analytics");
    QPushButton *goalsBtn     = new QPushButton("📅 Goals");
    QPushButton *reviewyBtn   = new QPushButton("🗓️ Review");
    QPushButton *helpBtn      = new QPushButton("❓ Help");

    QList<QPushButton*> buttons = { dashboardBtn, recordBtn, analyticsBtn, goalsBtn, reviewyBtn, helpBtn };
    for (auto btn : buttons) {
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setMinimumHeight(40);
        btn->setStyleSheet(
            "color: #2c3e50;"
            "background-color: #e0e0e0;"
            "border: none;"
            "border-radius: 5px;"
            "padding: 8px;"
            );
        navLayout->addWidget(btn);
    }
    connect(buttons[0], &QPushButton::clicked, this, &analysisWindow::openHome);


    // 🧩 Layout composition
    QWidget *centralWidget = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget);
    setCentralWidget(centralWidget);
    this->showMaximized();

   /* // 🔁 Connections
    connect(dashboardBtn, &QPushButton::clicked, this, [=]() {
        this->hide();
        homeWindow *home_window = new homeWindow(currentUserEmail, this);
        connect(home_window, &homeWindow::windowClosed, this, &analysisWindow::show);
        home_window->showMaximized();
    });

    connect(recordBtn, &QPushButton::clicked, this, &analysisWindow::on_pushButton_clicked);
    connect(reviewyBtn, &QPushButton::clicked, this, &analysisWindow::on_pushButton_2_clicked);
    connect(analyticsBtn, &QPushButton::clicked, this, &analysisWindow::on_pushButton_3_clicked);
    connect(goalsBtn, &QPushButton::clicked, this, &analysisWindow::on_pushButton_4_clicked);
    // You can later connect helpBtn to a dedicated slot*/
}

analysisWindow::~analysisWindow()
{
    delete ui;
}

void analysisWindow::on_pushButton_clicked()
{
    this->hide();
    budget_window = new budgetWindow(currentUserEmail, this);
    connect(budget_window, &budgetWindow::windowClosed, this, &analysisWindow::show);
    budget_window->showMaximized();
}

void analysisWindow::on_pushButton_2_clicked()
{
    this->hide();
    rev_window = new revWindow(currentUserEmail, this);
    connect(rev_window, &revWindow::windowClosed, this, &analysisWindow::show);
    rev_window->showMaximized();
}

void analysisWindow::on_pushButton_3_clicked()
{
    this->hide();
    weekly_window = new weeklyWindow(currentUserEmail, this);
    connect(weekly_window, &weeklyWindow::windowClosed, this, &analysisWindow::show);
    weekly_window->showMaximized();
}

void analysisWindow::on_pushButton_4_clicked()
{
    this->hide();
    monthly_window = new monthlyWindow(currentUserEmail, this);
    connect(monthly_window, &monthlyWindow::windowClosed, this, &analysisWindow::show);
    monthly_window->showMaximized();
}

void analysisWindow::openHome()
{

   home_window = new homeWindow(currentUserEmail, currentUserId, this);


    home_window->show();
    this->hide();
}
