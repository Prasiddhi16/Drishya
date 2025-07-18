#ifndef EXPERT_H
#define EXPERT_H

#include <QMainWindow>


namespace Ui {
class expert;
}

class expert : public QMainWindow
{
    Q_OBJECT

public:
    explicit expert(QWidget *parent = nullptr);
    ~expert();

private:
    Ui::expert *ui;
private slots:
    void loadExpertReviewPage();
};

#endif // EXPERT_H
