#include "finaldial.h"
#include "ui_finaldial.h"
#include "review.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

finaldial::finaldial(bool isMarried,
                     const QString &employment,
                     bool isResident,
                     int userId,
                     QWidget *parent)
    : QDialog(parent),
    ui(new Ui::finaldial),
    isMarried(isMarried),
    employment(employment),
    isResident(isResident),
    userId(userId)
{
    ui->setupUi(this);

    // 🌿 Label styling
    ui->Label->setStyleSheet(
        "QLabel {"
        "  font-size: 16px;"
        "  color: #2E8B57;"
        "  background-color: #f9f9f9;"
        "  border: 1px solid #ccc;"
        "  border-radius: 6px;"
        "  padding: 8px 12px;"
        "  min-width: 220px;"
        "  qproperty-alignment: AlignCenter;"
        "}"
        );

    calculateTax(); // Automatically calculates on open
}

finaldial::~finaldial() {
    delete ui;
}

void finaldial::calculateTax() {
    double incomeAmount = 0.0;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "FinalDialConnection");
    db.setDatabaseName("centralized.db");

    if (!db.open()) {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT income_amount FROM records WHERE user_id = :uid");
    query.bindValue(":uid", userId);

    if (query.exec() && query.next()) {
        incomeAmount = query.value(0).toDouble();
        qDebug() << "Income fetched for UID" << userId << ":" << incomeAmount;
    } else {
        QMessageBox::warning(this, "Data Error", "Unable to fetch income amount.");
        db.close();
        return;
    }

    db.close();

    // 💰 Tax logic
    double taxRate;
    if (isMarried && employment == "Employed" && isResident)
        taxRate = 0.10;
    else if (!isMarried && employment == "Self-employed" && !isResident)
        taxRate = 0.25;
    else if (!isMarried && employment == "Unemployed" && !isResident)
        taxRate = 0.00;
    else if (!isMarried && employment == "Employed" && isResident)
        taxRate = 0.30;
    else if (isMarried && employment == "Employed" && !isResident)
        taxRate = 0.20;
    else if (isMarried && employment == "Self-employed" && isResident)
        taxRate = 0.15;
    else if (isMarried && employment == "Self-employed" && !isResident)
        taxRate = 0.20;
    else if (isMarried && employment == "Unemployed")
        taxRate = 0.00;

    qDebug() << "isMarried:" << isMarried;
    qDebug() << "employment:" << employment;
    qDebug() << "isResident:" << isResident;

    double taxToPay = incomeAmount * taxRate;

    ui->Label->setText(QString("Taxable Amount: Rs. %1").arg(taxToPay, 0, 'f', 2));
}

void finaldial::on_pushButton_clicked() {
    review *review_win = new review(currentUserName, currentUserEmail, userId, this);
    review_win->show();
    this->hide();
}
