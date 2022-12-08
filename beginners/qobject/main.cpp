#include <QCoreApplication>
#include <QDebug>
#include "cat.h"
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
    cat.setObjectName("Mr Grinch");

    Dog dog;
    dog.setObjectName("Terminator");

    QObject::connect(&dog, &Dog::bark, &cat, &Cat::scared);
    QObject::connect(&cat, &Cat::run, &dog, &Dog::chase);

    emit dog.bark();

    return a.exec();
}
