#ifndef FINALDIAL_H
#define FINALDIAL_H

#include <QDialog>

namespace Ui {
class finaldial;
}

class finaldial : public QDialog
{
    Q_OBJECT

public:
    explicit finaldial(QWidget *parent = nullptr);
    ~finaldial();

private:
    Ui::finaldial *ui;
};

#endif // FINALDIAL_H
