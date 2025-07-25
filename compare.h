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

    explicit compare(const QString &userEmail, int userId, QWidget *parent = nullptr);
    ~compare();
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void windowClosed();

private:
    Ui::compare *ui;
    int m_userId;

    void setupChart();
};

#endif // COMPARE_H
