#include "Help.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Help w;
    w.show();
    return a.exec();
}
