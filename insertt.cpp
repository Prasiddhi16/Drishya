#include "insertt.h"
#include "ui_insertt.h"
#include"goaldata.h"
#include<QPixmap>
#include<QMessageBox>
#include<QRegularExpression>
#include<QRegularExpressionValidator>
#include<QStandardPaths>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDir>
#include<QFileInfo>
#include <QUuid>

Insertt::Insertt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Insertt)
{
    ui->setupUi(this);
    //adding image
    QPixmap pix(":/img/img/goal2.jpg");
    int w=ui->label_pic->width();
    int h=ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h));

    //adding placeholders
    ui->goalNameEdit->setPlaceholderText("");
    ui->incomeEdit->setPlaceholderText("In NRs");
    ui->downpaymentEdit->setPlaceholderText("In NRs");
    ui->durationEdit->setPlaceholderText("In months");

    //adding limitations to what can and cannot be written in form
    QRegularExpression rx("[A-Za-z ]+");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->goalNameEdit->setValidator(validator);
    ui->incomeEdit->setValidator(new QDoubleValidator(0, 1000000000, 2, this));
    ui->downpaymentEdit->setValidator(new QDoubleValidator(0, 1000000000, 2, this));
    ui->durationEdit->setValidator(new QIntValidator(0, 1000000000, this));
}

Insertt::~Insertt()
{
    delete ui;
}
/*void Insertt::on_Save_clicked()
{
QMessageBox::information(this,"GOAL","Your goal is set.You are now one step closer to success.");*/
void Insertt::on_Save_clicked()
{
    // Database path
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/goal.db";
    QDir().mkpath(QFileInfo(path).absolutePath());

    QSqlDatabase db;
    if (QSqlDatabase::contains("goal_connection")) {
        db = QSqlDatabase::database("goal_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "goal_connection");
        db.setDatabaseName(path);
    }

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    // Create table if not exists
    QSqlQuery createQuery(db);
    QString createSql = R"(
        CREATE TABLE IF NOT EXISTS goals (
            goal_id TEXT PRIMARY KEY,
            goal_name TEXT,
            required_amount REAL,
            downpayment REAL,
            time_limit INTEGER
        )
    )";

    if (!createQuery.exec(createSql)) {
        QMessageBox::critical(this, "Database Error", "Failed to create table: " + createQuery.lastError().text());
        db.close();
        return;
    }

    // Input
    GoalData data;
    data.name = ui->goalNameEdit->text();
    data.incomeRequired = ui->incomeEdit->text().toDouble();
    data.downpayment = ui->downpaymentEdit->text().toDouble();
    data.duration = ui->durationEdit->text().toInt();  // Now numeric

    if (data.name.isEmpty() || ui->incomeEdit->text().isEmpty() ||
        ui->downpaymentEdit->text().isEmpty() || ui->durationEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        db.close();
        return;
    }
    // Validate downpayment amount
    if (data.downpayment > data.incomeRequired) {
        QMessageBox::warning(this, "Input Error", "Downpayment cannot be greater than required income.");
        db.close();
        return;
    }

    // Check if goal name already exists
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT * FROM goals WHERE goal_name = ?");
    checkQuery.bindValue(0, data.name);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Query Error", checkQuery.lastError().text());
        db.close();
        return;
    }

    if (checkQuery.next()) {
        // Prompt to edit
        QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Goal Exists",
            "A goal with this name already exists.\nDo you want to edit the data?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (reply == QMessageBox::Yes) {
            // Edit existing
            QSqlQuery updateQuery(db);
            updateQuery.prepare(R"(
                UPDATE goals
                SET required_amount = ?, downpayment = ?, time_limit = ?
                WHERE goal_name = ?
            )");
            updateQuery.bindValue(0, data.incomeRequired);
            updateQuery.bindValue(1, data.downpayment);
            updateQuery.bindValue(2, data.duration);
            updateQuery.bindValue(3, data.name);

            if (!updateQuery.exec()) {
                QMessageBox::critical(this, "Update Error", updateQuery.lastError().text());
                db.close();
                return;
            }

            db.close();
            emit goalSet(data);
            accept();
            return;
        } else {
            // User chose not to edit
            db.close();
            return;
        }
    }

    // Insert new goal
    QString goalId = QUuid::createUuid().toString(QUuid::WithoutBraces);

    QSqlQuery insertQuery(db);
    insertQuery.prepare(R"(
        INSERT INTO goals (goal_id, goal_name, required_amount, downpayment, time_limit)
        VALUES (?, ?, ?, ?, ?)
    )");
    insertQuery.bindValue(0, goalId);
    insertQuery.bindValue(1, data.name);
    insertQuery.bindValue(2, data.incomeRequired);
    insertQuery.bindValue(3, data.downpayment);
    insertQuery.bindValue(4, data.duration);

    if (!insertQuery.exec()) {
        QMessageBox::critical(this, "Insert Error", insertQuery.lastError().text());
        db.close();
        return;
    }

    db.close();

    emit goalSet(data);
    accept();
}
