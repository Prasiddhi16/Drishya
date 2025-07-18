#ifndef REVIEW_H
#define REVIEW_H

#include <QMainWindow>
#include <expert.h>
#include <compare.h>
#include <expense.h>
#include <graph.h>
#include<taxdialog.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class review;
}
QT_END_NAMESPACE

class review : public QMainWindow
{
    Q_OBJECT

public:
    explicit review(QWidget *parent = nullptr);
    ~review();

private slots:
    void on_btnCompare_clicked();

    void on_btnExper_clicked();

   void on_btnExpense_clicked();

   // void on_pushButton_clicked();

    void on_btnTax_clicked();

private:
    Ui::review *ui;
     class compare *Compare;
    class expert *Expert;
      //expense *Expense;
   class graph*Graph;
    class taxDialog *Taxdialog;
  //  historypage *History;
};
#endif // REVIEW_H
