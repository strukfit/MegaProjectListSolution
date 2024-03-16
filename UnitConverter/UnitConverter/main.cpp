#include "UnitConverter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UnitConverter w;
    w.show();
    return a.exec();
}
