#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDateEdit>
#include <QPushButton>

class historypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit historypage(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~historypage();

private slots:
    void loadFilteredData();
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();
private:
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;

    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *viewHistoryButton;
    QSqlQueryModel *model;
    QTableView *tableView;
};

#endif // HISTORYPAGE_H
