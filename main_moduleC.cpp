#include "review.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError> // Include for QSqlError
#include <QDebug>    // Include for qDebug
#include <QMessageBox> // For critical messages

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    review w;
    w.show();


    // Get the database connection. If it doesn't exist, add it.
    // This ensures only one connection named "MainConnection" is managed globally.
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MainConnection");

    // Set the database file name to the new, corrected path.
    db.setDatabaseName("C:/Users/Lenovo/OneDrive/Desktop/itsdrishya/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/database.db"); // <--- UPDATED PATH

    // Attempt to open the database connection.
    if (!db.open()) {
        // If opening fails, print a detailed error message.
        qDebug() << "ERROR: Failed to open database in main.cpp:" << db.lastError().text();
        // In a production app, you might show a critical message box here and exit.
        QMessageBox::critical(nullptr, "Database Error", "Failed to connect to the application database. Please ensure 'Artha1.db' exists and is accessible.");
        return 1; // Return non-zero to indicate an error
    } else {
        qDebug() << "Database connection successful in main.cpp.";
    }

    // Create and show the main window.
    //review w;
   // w.show();

    // Start the application event loop.
    return a.exec();
}
