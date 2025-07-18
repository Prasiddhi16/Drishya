#include "visions.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visions w;
    w.show();
    return a.exec();
}
