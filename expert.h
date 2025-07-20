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
    QString m_userEmail;  // 👤 Stores user's email
    QString m_userName;   // 🪪 Optional: Extracted or set name
    int m_userId;         // 🔐 Unique user identifier

private slots:
    void connectToDatabase();        // Initializes MainConnection
    void loadExpertReviewPage();     // Loads chart and insights
    QString generateInsight(const QVector<double> &values, double threshold, const QString &label);
    void clearChartLayout();         // Clears previous chart layout
};

#endif // EXPERT_H
