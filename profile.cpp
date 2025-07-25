#include "profile.h"
#include "ui_profile.h"
#include"loginwindow.h"
#include <QString>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QFileInfo>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>
#include <QTimer>
#include <algorithm>

profile::profile(int userId, const QString &userEmail, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::profile),
    m_userId(userId),
    m_userEmail(userEmail)
{
    ui->setupUi(this);

    // Initialize database connection for profile window
    m_db = QSqlDatabase::addDatabase("QSQLITE", "profile_connection");
    QString dbFilePath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../centralized.db");
    m_db.setDatabaseName(dbFilePath);

    if (!m_db.open()) {
        qDebug() << "Failed to open database for profile:" << m_db.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to open database for profile settings.");
    } else {
        qDebug() << "Database connected for profile successfully!";
        loadUserData(); // Load user data when the profile window opens
    }
    ui->stackedWidget->setCurrentIndex(0);

    // Set icons for tool buttons
    QPixmap pix1(":/img/img/details.png");
    ui->toolButton_1->setIcon(QIcon(pix1));
    ui->toolButton_1->setIconSize(ui->toolButton_1->size());

    QPixmap pix2(":/img/img/edit.png");
    ui->toolButton_2->setIcon(QIcon(pix2));
    ui->toolButton_2->setIconSize(ui->toolButton_2->size());

    QPixmap pix3(":/img/img/Privacy.png");
    ui->toolButton_3->setIcon(QIcon(pix3));
    ui->toolButton_3->setIconSize(ui->toolButton_3->size());

    QPixmap pix4(":/img/img/report.png");
    ui->toolButton_4->setIcon(QIcon(pix4));
    ui->toolButton_4->setIconSize(ui->toolButton_4->size());


    QPixmap pix6(":/img/img/logout.png");
    ui->toolButton_6->setIcon(QIcon(pix6));
    ui->toolButton_6->setIconSize(ui->toolButton_6->size());

    // Setting arrow types
    ui->about->setArrowType(Qt::RightArrow);
    ui->edit->setArrowType(Qt::RightArrow);
    ui->privacy->setArrowType(Qt::RightArrow);
    ui->report->setArrowType(Qt::RightArrow);
    ui->backButton_1->setArrowType(Qt::LeftArrow);
    ui->backButton_2->setArrowType(Qt::LeftArrow);
    ui->backButton_3->setArrowType(Qt::LeftArrow);
    ui->backButton_4->setArrowType(Qt::LeftArrow);

    ui->reviewbox->setPlaceholderText("Your feedback and suggestions are appreciated.Share your feedback, suggestions, or report any issues.\nThank you!");

    // Connecting the stacked widgets
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
        // Clear password fields when returning from edit page
        ui->current_pass->clear();
        ui->new_pass->clear();
        ui->confirm_pass->clear();
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

    // Password eye toggle for current_pass, new_pass, confirm_pass
    setupPasswordEyeToggle(ui->current_pass);
    setupPasswordEyeToggle(ui->new_pass);
    setupPasswordEyeToggle(ui->confirm_pass);
}

profile::~profile()
{
    // Close the database connection when the profile window is destroyed
    if (m_db.isOpen()) {
        m_db.close();
        QSqlDatabase::removeDatabase("profile_connection");
    }
    delete ui;
}

void profile::loadUserData()
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open for loading user data.";
        return;
    }

    QSqlQuery query(m_db);
    query.prepare("SELECT name, email, dob FROM user WHERE id = :userId");
    query.bindValue(":userId", m_userId);

    if (query.exec() && query.next()) {
        // Assuming you have QLabel widgets named label_username_about, label_email_about, label_dob_about
        // on your "About You" page to display these values
        ui->hello->setText("Hello, " + (query.value("name").toString()) + "!");
        ui->aboutuser->setText(query.value("name").toString());
        ui->emailuser->setText(query.value("email").toString());
        ui->dobuser->setText(query.value("dob").toString());

        // Assuming ui->user is a QLineEdit for editing the username on the "Edit Your Profile" page.
        ui->user->setText(query.value("name").toString());
    } else {
        qDebug() << "Failed to load user data:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to load user profile data.");
    }
}

QString profile::hashPassword(const QString &password)
{
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hashed.toHex());
}

void profile::on_saveChanges_clicked()
{
    QString newUsername = ui->user->text().trimmed();
    QString currentPassword = ui->current_pass->text().trimmed();
    QString newPassword = ui->new_pass->text().trimmed();
    QString confirmPassword = ui->confirm_pass->text().trimmed();

    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database not open to save changes.");
        return;
    }

    bool changesMade = false;

    // --- Username Change ---
    // Fetch current username to check if it's different
    QSqlQuery currentNameQuery(m_db);
    currentNameQuery.prepare("SELECT name FROM user WHERE id = :userId");
    currentNameQuery.bindValue(":userId", m_userId);
    QString originalUsername;
    if (currentNameQuery.exec() && currentNameQuery.next()) {
        originalUsername = currentNameQuery.value("name").toString();
    }

    if (newUsername != originalUsername) {
        if (newUsername.isEmpty()) {
            QMessageBox::warning(this, "Invalid Username", "Username cannot be empty.");
            return;
        }
        if (!QRegularExpression("^[A-Za-z\\s]+$").match(newUsername).hasMatch()) {
            QMessageBox::warning(this, "Invalid Username", "Username must contain only letters and spaces.");
            return;
        }

        QSqlQuery updateNameQuery(m_db);
        updateNameQuery.prepare("UPDATE user SET name = :newName WHERE id = :userId");
        updateNameQuery.bindValue(":newName", newUsername);
        updateNameQuery.bindValue(":userId", m_userId);

        if (!updateNameQuery.exec()) {
            qDebug() << "Failed to update username:" << updateNameQuery.lastError().text();
            QMessageBox::warning(this, "Error", "Failed to update username.");
        } else {
            QMessageBox::information(this, "Success", "Username updated successfully!");
            changesMade = true;
            // Reload user data to update the "About You" page immediately
            loadUserData();
        }
    }

    // --- Password Change ---
    if (!currentPassword.isEmpty() || !newPassword.isEmpty() || !confirmPassword.isEmpty()) {
        if (currentPassword.isEmpty()) {
            QMessageBox::warning(this, "Missing Input", "Please enter your current password to change it.");
            return;
        }

        if (newPassword.isEmpty() || confirmPassword.isEmpty()) {
            QMessageBox::warning(this, "Missing Input", "Please enter and confirm your new password.");
            return;
        }

        if (newPassword != confirmPassword) {
            QMessageBox::warning(this, "Mismatch", "The new password does not match.");
            return;
        }

        // Password strength validation (similar to signup/forgot password)
        if (newPassword.length() < 8 ||
            std::count_if(newPassword.begin(), newPassword.end(), [](const QChar &ch) { return ch.isDigit(); }) < 3) {
            QMessageBox::warning(this, "Weak Password", "New password must be at least 8 characters and include at least 3 numbers.");
            return;
        }

        // Verify current password
        QSqlQuery verifyPassQuery(m_db);
        verifyPassQuery.prepare("SELECT password FROM user WHERE id = :userId");
        verifyPassQuery.bindValue(":userId", m_userId);

        if (verifyPassQuery.exec() && verifyPassQuery.next()) {
            QString storedHashedPassword = verifyPassQuery.value("password").toString();
            QString hashedCurrentPassword = hashPassword(currentPassword);

            if (hashedCurrentPassword == storedHashedPassword) {
                // Current password is correct, proceed to update
                QString hashedNewPassword = hashPassword(newPassword);

                QSqlQuery updatePassQuery(m_db);
                updatePassQuery.prepare("UPDATE user SET password = :newPassword WHERE id = :userId");
                updatePassQuery.bindValue(":newPassword", hashedNewPassword);
                updatePassQuery.bindValue(":userId", m_userId);

                if (updatePassQuery.exec()) {
                    QMessageBox::information(this, "Success", "Password changed successfully!");
                    // Clear password fields after successful change
                    ui->current_pass->clear();
                    ui->new_pass->clear();
                    ui->confirm_pass->clear();
                    changesMade = true;
                } else {
                    qDebug() << "Failed to update password:" << updatePassQuery.lastError().text();
                    QMessageBox::warning(this, "Error", "Failed to change password due to database error.");
                }
            } else {
                QMessageBox::warning(this, "Incorrect Password", "The current password you entered is incorrect.");
            }
        } else {
            qDebug() << "Failed to retrieve current password:" << verifyPassQuery.lastError().text();
            QMessageBox::critical(this, "Error", "Could not verify current password. Please try again.");
        }
    }

    if (!changesMade && currentPassword.isEmpty() && newPassword.isEmpty() && confirmPassword.isEmpty() && newUsername == originalUsername) {
        QMessageBox::information(this, "No Changes", "No changes were detected or saved.");
    }
}

void profile::setupPasswordEyeToggle(QLineEdit *lineEdit)
{
    QToolButton *eyeButton = new QToolButton(lineEdit);
    eyeButton->setText("👁");
    eyeButton->setCursor(Qt::PointingHandCursor);
    eyeButton->setStyleSheet("QToolButton { border: none; font-size: 8px; padding: 0px; }");

    QHBoxLayout *layout = new QHBoxLayout(lineEdit);
    layout->addStretch();
    layout->addWidget(eyeButton);
    layout->setContentsMargins(0, 0, 0, 0);
    lineEdit->setLayout(layout);
    lineEdit->setEchoMode(QLineEdit::Password); // Ensure it starts as password

    connect(eyeButton, &QToolButton::clicked, this, [=]() {
        if (lineEdit->echoMode() == QLineEdit::Password) {
            lineEdit->setEchoMode(QLineEdit::Normal);
        } else {
            lineEdit->setEchoMode(QLineEdit::Password);
        }
    });
}

void profile::on_revbutton_clicked()
{
    QMessageBox::information(this,"Message Received", "Thank you for the feedback!");
}
    void profile::on_logout_clicked()
{
    qDebug() << "Logging out from Profile window";

    // Disable persistent login
    QSettings settings("YourOrganization", "YourApp");
    settings.setValue("keepMeLoggedIn", 0);

    // Show login window
    login_window = new loginWindow();
    login_window->show();

    // Close the current profile window
    this->close();
}


