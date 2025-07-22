#ifndef COMPARE_H
#define COMPARE_H

#include <QMainWindow>

namespace Ui {
class compare;
}

class compare : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor takes userEmail and userId
    explicit compare(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~compare();
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::compare *ui;
    int m_userId; // Renamed for clarity, stores the user ID

    void setupChart(); // Private helper function to set up the chart
};

#endif // COMPARE_H
