#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QMainWindow>
#include <QDateEdit>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QCloseEvent>

class historypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit historypage(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~historypage();

signals:
    void windowClosed();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void loadFilteredData();

private:
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;

    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *viewHistoryButton;
    QTableView *tableView;
    QSqlQueryModel *model;
};

#endif // HISTORYPAGE_H
