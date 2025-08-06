#include <QCloseEvent>
#include "taxDialog.h"
#include "secdialog.h"
#include "ui_secdialog.h"
#include "thirddialog.h"
#include "taxDialog.h"
#include <QMessageBox>
#include <QDebug>

secDialog::secDialog(const QString &userEmail,
                     int userId,
                     bool isMarried,
                     const QString &employment,
                     QWidget *parent)
    : QDialog(parent),
    ui(new Ui::secDialog),
    currentUserEmail(userEmail),
    currentUserId(userId),
    isMarried(isMarried),
    employment(employment)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_eyes_clicked()
{
    QString selectedEmployment;
    if (ui->radioButton->isChecked())        selectedEmployment = "Employed";
    else if (ui->radioButton_2->isChecked()) selectedEmployment = "Self-employed";
    else if (ui->radioButton_3->isChecked()) selectedEmployment = "Unemployed";

    if (!selectedEmployment.isEmpty()) {
        thirdDialog *dialog = new thirdDialog(currentUserEmail, currentUserId, isMarried, selectedEmployment, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(dialog, &QDialog::finished, this, &QWidget::show);
        this->hide();
        dialog->show();
    } else {

        QMessageBox::information(this, "Information", "Please select an option.");
        qDebug() << "User prompted to select an employment option.";
    }
}

void secDialog::on_eno_clicked()
{
    taxDialog *dialog = new taxDialog(currentUserEmail, currentUserId, this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(dialog, &QDialog::finished, this, &QWidget::show);
    this->hide();
    dialog->show();
}
void secDialog::closeEvent(QCloseEvent *event)
{
    taxDialog *dialog = new taxDialog(currentUserEmail, currentUserId, nullptr);
    dialog->show();
    event->accept();
}
