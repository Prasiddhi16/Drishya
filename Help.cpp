#include "Help.h"
#include "ui_Help.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QSizePolicy>

Help::Help(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help)
{
    ui->setupUi(this);

    // Create a container widget for nav bar
    QWidget *navContainer = new QWidget(this);
    navContainer->setStyleSheet("background-color: white;");
    navContainer->setFixedWidth(170);

    // Create vertical layout for navContainer
    QVBoxLayout *navLayout = new QVBoxLayout(navContainer);
    navLayout->setContentsMargins(0, 0, 0, 0);
    navLayout->setSpacing(10);

    QFont navFont("Segoe UI", 10, QFont::Bold);

    QPushButton *dashboardBtn = new QPushButton("🏠 Home");
    QPushButton *recordBtn    = new QPushButton("📊 Add Record");
    QPushButton *analyticsBtn = new QPushButton("📝 Analytics");
    QPushButton *goalsBtn     = new QPushButton("📅 Goals");
    QPushButton *reviewyBtn   = new QPushButton("🗓 Review");
    QPushButton *helpBtn      = new QPushButton("❓ Help");

    QList<QPushButton*> buttons = { dashboardBtn, recordBtn, analyticsBtn, goalsBtn, reviewyBtn, helpBtn };
    navLayout->addSpacing(10);
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

    navLayout->addStretch();  // Push buttons to top

    // Now, insert navContainer and your UI's centralwidget side by side

    // Create a main horizontal layout container widget
    QWidget *mainWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Take the original central widget from UI
    QWidget *originalCentral = ui->centralwidget;

    // Important: remove original central widget from QMainWindow before reparenting
    ui->centralwidget->setParent(nullptr);

    // Add navContainer and original centralwidget side by side
    mainLayout->addWidget(navContainer, 1);        // navigation bar takes 1 part
    mainLayout->addWidget(originalCentral, 4);     // rest for content

    // Set mainWidget as new central widget
    setCentralWidget(mainWidget);
}

Help::~Help()
{
 delete ui;
}
