#ifndef EXPENSE_H
#define EXPENSE_H

#include <QWidget>
#include "graph.h"
namespace Ui {
class expense;
}

class expense : public QWidget
{
    Q_OBJECT

public:
    explicit expense(QWidget *parent = nullptr);
    ~expense();

private slots:
    void on_pushButton_clicked();

private:
    Ui::expense *ui;
       graph *Graph;
};

#endif // EXPENSE_H
