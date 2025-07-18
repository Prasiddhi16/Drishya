#ifndef HELP_H
#define HELP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Help;
}
QT_END_NAMESPACE

class Help : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;
};

#endif // HELP_H
