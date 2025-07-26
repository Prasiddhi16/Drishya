#ifndef EXPERT_H
#define EXPERT_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class expert;
}

class expert : public QMainWindow
{
    Q_OBJECT

public:
    explicit expert(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~expert();

private:
    Ui::expert *ui;
    QString m_userEmail;
    QString m_userName;
    int m_userId;
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private slots:
    void connectToDatabase();
    void loadExpertReviewPage();     // Loads chart and insights
    QString generateInsight(const QVector<double> &values, double threshold, const QString &label);
    void clearChartLayout();         // Clears previous chart layout
};

#endif // EXPERT_H
