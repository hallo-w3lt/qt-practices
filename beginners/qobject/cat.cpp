#include "cat.h"

Cat::Cat(QObject *parent) : QObject{parent}
{
    // ...
}

void Cat::scared()
{
    qInfo() << "Scared!, running";
    emit run();
}
