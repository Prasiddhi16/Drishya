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
    explicit historypage(QWidget *parent = nullptr);
    ~historypage();

private slots:
    void loadFilteredData();

private:
    QSqlQueryModel *model;
    QTableView *tableView;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *viewHistoryButton;
};

#endif // HISTORYPAGE_H
