#include "radio.h"
#include <QDebug>

Radio::Radio(QObject *parent) : QObject{parent}
{
    // ...
}

void Radio::listen(int channel, QString name, QString message)
{
    qInfo() << channel << " " << name << " - " << message;
}
