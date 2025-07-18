#ifndef RECORD_WINDOW_H
#define RECORD_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RecordWindow; }
QT_END_NAMESPACE

class RecordWindow : public QMainWindow
{
    Q_OBJECT

public:
    RecordWindow(QWidget *parent = nullptr);
    ~RecordWindow();

private slots:
    void addRecord();
    void editIncome();
    void editExpense();

private:
    Ui::RecordWindow *ui;
    QString userId;
    QString userEmail;

    // Dialog function for editing income/expense
    bool showEditDialog(const QString& title, const QString& labelText,
                        QString& amount, QString& sourceOrCategory, QString& timestamp);
};

#endif // RECORD_WINDOW_H
