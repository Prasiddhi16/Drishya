#ifndef REVWINDOW_H
#define REVWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QTimer>
#include <QtCharts/QChartView>


namespace Ui {
class revWindow;
}

class revWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit revWindow(const QString &userEmail,int userId, QWidget *parent = nullptr);
    ~revWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::revWindow *ui;
    QString currentUserEmail;
     int currentUserId;
    QTimer *refreshTimer;
    QChartView *chartView;
    void refreshChart();

};

#endif // REVWINDOW_H
