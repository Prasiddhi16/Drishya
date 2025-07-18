#include "profile.h"
#include "ui_profile.h"
#include<Qstring>
#include<QPixmap>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDir>
#include<QFileInfo>


profile::profile(QWidget *parent)
    : QDialog(parent), ui(new Ui::profile)
{
    ui->setupUi(this);
   // QToolButton *toolButton_1 = new QToolButton(this);
    QPixmap pix1(":/img/img/details.png");
    int w1 = ui->toolButton_1->width();
    int h1 = ui->toolButton_1->height();
    ui->toolButton_1->setIcon(QIcon(pix1));
    ui->toolButton_1->setIconSize(QSize(w1, h1));


    QPixmap pix2(":/img/img/edit.png");
    int w2 = ui->toolButton_2->width();
    int h2 = ui->toolButton_2->height();
    ui->toolButton_2->setIcon(QIcon(pix2));
    ui->toolButton_2->setIconSize(QSize(w2, h2));

    QPixmap pix3(":/img/img/Privacy.png");
    int w3 = ui->toolButton_3->width();
    int h3 = ui->toolButton_3->height();
    ui->toolButton_3->setIcon(QIcon(pix3));
    ui->toolButton_3->setIconSize(QSize(w3, h3));

    QPixmap pix4(":/img/img/report.png");
    int w4 = ui->toolButton_4->width();
    int h4 = ui->toolButton_4->height();
    ui->toolButton_4->setIcon(QIcon(pix4));
    ui->toolButton_4->setIconSize(QSize(w4, h4));

    QPixmap pix5(":/img/img/swap.png");
    int w5 = ui->toolButton_5->width();
    int h5 = ui->toolButton_5->height();
    ui->toolButton_5->setIcon(QIcon(pix5));
    ui->toolButton_5->setIconSize(QSize(w5, h5));

    QPixmap pix6(":/img/img/logout.png");
    int w6 = ui->toolButton_6->width();
    int h6 = ui->toolButton_6->height();
    ui->toolButton_6->setIcon(QIcon(pix6));
    ui->toolButton_6->setIconSize(QSize(w6, h6));

   //setting arrow
    ui->about->setArrowType(Qt::RightArrow);
    ui->edit->setArrowType(Qt::RightArrow);
    ui->privacy->setArrowType(Qt::RightArrow);
    ui->report->setArrowType(Qt::RightArrow);
    ui->backButton_1->setArrowType(Qt::LeftArrow);
    ui->backButton_2->setArrowType(Qt::LeftArrow);
    ui->backButton_3->setArrowType(Qt::LeftArrow);
    ui->backButton_4->setArrowType(Qt::LeftArrow);


    //connecting the stacked widgets
    connect(ui->about, &QToolButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1); // switch to about form
    });

    connect(ui->backButton_1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // return to settings
    });

    connect(ui->edit, &QToolButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2); // switch to edit form
    });

    connect(ui->backButton_2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // return to settings
    });

    connect(ui->privacy, &QToolButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3); // switch to privacy form
    });

    connect(ui->backButton_3, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // return to settings
    });

    connect(ui->report,&QToolButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(4); // switch to report form
    });

    connect(ui->backButton_4, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // return to settings
    });


}

profile::~profile()
{
    delete ui;
}


void profile::on_saveChanges_clicked()
{
    QString Username = ui->user->text();
    QString Current_Password = ui->current_pass->text();
    QString New_Password = ui->new_pass->text();
    QString Confirm_Password = ui->confirm_pass->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Qtdata.db");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";
    }

}

