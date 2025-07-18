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
    explicit compare(QWidget *parent = nullptr);
    ~compare();

private:
    Ui::compare *ui;
    void setupChart();
};

#endif // COMPARE_H
