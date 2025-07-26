#include "insertt.h"
#include "ui_insertt.h"
#include "goaldata.h" // Ensure GoalData is included
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>


Insertt::Insertt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Insertt)
{
    ui->setupUi(this);
    // adding image
    QPixmap pix(":/img/img/goal2.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w, h));

    // adding placeholders
    ui->goalNameEdit->setPlaceholderText("");
    ui->incomeEdit->setPlaceholderText("Set target amount");
    ui->downpaymentEdit->setPlaceholderText("Specify initial amount");
    ui->durationEdit->setPlaceholderText("Enter duration in months");

    // adding limitations to what can and cannot be written in form
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


void Insertt::setGoalData(const GoalData &data) {
    currentGoalData = data; // Store the incoming data, including its ID if it's an existing goal

    // Populate UI fields with the received data
    ui->goalNameEdit->setText(data.name);
    // Use conditional operators to display empty string if value is 0, otherwise format the number

    ui->incomeEdit->setText(data.incomeRequired == 0.0 ? "" : QString::number(data.incomeRequired, 'f', 2));
    ui->downpaymentEdit->setText(data.downpayment == 0.0 ? "" : QString::number(data.downpayment, 'f', 2));
    ui->durationEdit->setText(data.duration == 0 ? "" : QString::number(data.duration));
    ui->goalNameEdit->setReadOnly(false);// Can be set to true if name shouldn't change on edit

    }

void Insertt::on_Save_clicked()
{
    // 1. Input Validation
    QString name = ui->goalNameEdit->text().trimmed();
    bool incomeValid, downpaymentValid, durationValid;
    double incomeRequired = ui->incomeEdit->text().toDouble(&incomeValid);
    double downpayment = ui->downpaymentEdit->text().toDouble(&downpaymentValid);
    int duration = ui->durationEdit->text().toInt(&durationValid);

    if (name.isEmpty() || !incomeValid || !downpaymentValid || !durationValid) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    if (duration <= 0) {
        QMessageBox::warning(this, "Input Error", "Duration must be greater than 0 months.");
        return;
    }
    if (incomeRequired<=0) {
        QMessageBox::warning(this, "Input Error", "Target amount must be greater than Rs.0.");
        return;
    }

    if (downpayment >= incomeRequired) {
        QMessageBox::warning(this, "Input Error", "Current balance cannot be greater than or equal to target amount.");
        return;
    }

    // 2. Create GoalData object to emit
    // Crucially, we use the ID from currentGoalData.
    // If currentGoalData was empty (new goal), its ID is empty, and Visions will generate a new UUID.
    // If currentGoalData had an ID (editing existing goal), that ID is preserved.
    GoalData dataToEmit;
    dataToEmit.id = currentGoalData.id; // Preserve existing ID for edits
    dataToEmit.name = name;
    dataToEmit.incomeRequired = incomeRequired;
    dataToEmit.downpayment = downpayment;
    dataToEmit.duration = duration;
    // slotIndex is managed by Visions, not set here

    // 3. Emit the signal and close the dialog
    emit goalSet(dataToEmit);
    QMessageBox::information(this, "Goal Set", "Your goal data has been saved.");
    accept(); // Close the dialog
}


void Insertt::on_cancel_clicked()
{
    reject();
}

