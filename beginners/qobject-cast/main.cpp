#include <QCoreApplication>
#include <QDebug>
#include "vater.h"
#include "sohn.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // from child class to parent class
    Sohn* sohn1 { new Sohn(&a)};
    Vater* vater { qobject_cast<Vater*>(sohn1) };

    qInfo() << vater->getABeer();

    // from parent class to child class
    Sohn* sohn2 {qobject_cast<Sohn*>(vater)};

    qInfo() << sohn2->playToGame();

    return a.exec();
}
