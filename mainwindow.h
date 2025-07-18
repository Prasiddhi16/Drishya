#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addRecord();
    void editIncome();
    void editExpense();

private:
    Ui::MainWindow *ui;
    QString userId;
    QString userEmail;

    // Dialog function for editing income/expense
    bool showEditDialog(const QString& title, const QString& labelText,
                        QString& amount, QString& sourceOrCategory, QString& timestamp);
};

#endif // MAINWINDOW_H
