#ifndef REVIEW_H
#define REVIEW_H
class homeWindow;
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
    explicit review(const QString &userName, const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~review();

private slots:
    void on_btnCompare_clicked();

    void on_btnExper_clicked();

   void on_btnExpense_clicked();

   // void on_pushButton_clicked();

    void on_btnTax_clicked();
   void openHome();
   void openAnalytics();

   void openvisions();
   void openRecordWindow();

private:
    Ui::review *ui;
     class compare *Compare;
    class expert *Expert;
      //expense *Expense;
   class graph*Graph;
    class taxDialog *Taxdialog;
  //  historypage *History;
    QString currentUserName;
    QString currentUserEmail;
    int currentUserId;

    homeWindow* home_window;
};
#endif // REVIEW_H
