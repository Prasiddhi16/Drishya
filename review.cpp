#include "review.h"
#include "ui_review.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QFrame>
#include <QSizePolicy>
#include <QMessageBox>
#include "historypage.h"



review::review(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::review)
{
    ui->setupUi(this);
    this->showMaximized();

    QFrame *navPanel = new QFrame;
    navPanel->setFixedWidth(170);
    navPanel->setStyleSheet("background-color: #ffffff;");

    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setAlignment(Qt::AlignTop);
    navLayout->setSpacing(10);
    navLayout->setContentsMargins(10, 20, 10, 10);

    QFont navFont("Arial", 10, QFont::Bold);

    QList<QPushButton*> navButtons = {
        new QPushButton("🏠 Home"),
        new QPushButton("➕ Add Records"),
        new QPushButton("📈 Analytics"),
        new QPushButton("🎯 Goals"),
        new QPushButton("📋 Review"),
        new QPushButton("❓ Help")
    };

    for (auto btn : navButtons) {
        btn->setFont(navFont);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setStyleSheet("color: #2c3e50; background-color: #e0e0e0; border: none; padding: 8px;");
        navLayout->addWidget(btn);
        btn->setFixedHeight(40);
    }


    QWidget *mainContainer = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(mainContainer);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(navPanel);
    mainLayout->addWidget(ui->centralwidget);

    this->setCentralWidget(mainContainer);
    // Step 3: Connect buttons to your slots
    connect(navButtons[0], &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Home", "Home clicked");
    });
    connect(navButtons[1], &QPushButton::clicked, this, &review::on_btnExper_clicked);
    connect(navButtons[2], &QPushButton::clicked, this, &review::on_btnExpense_clicked);
    connect(navButtons[3], &QPushButton::clicked, this, &review::on_btnCompare_clicked);
    connect(navButtons[4], &QPushButton::clicked, this, &review::on_btnTax_clicked);
}


review::~review()
{
    delete ui;
}

void review::on_btnCompare_clicked()
{
    hide();

    Compare= new compare(this);
    Compare->show();
}


void review::on_btnExper_clicked()
{
    hide();
    Expert= new expert(this);
    Expert->show();
}


void review::on_btnExpense_clicked()
{
    Graph=new graph(this);
    Graph->show();
}

void review::on_btnTax_clicked()
{
    Taxdialog=new taxDialog(this);
    Taxdialog->show();
}

