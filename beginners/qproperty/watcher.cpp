#include "watcher.h"
#include <QDebug>

Watcher::Watcher(QObject *parent) : QObject{parent}
{
    // ...
}

void Watcher::messageChanged(QString &message)
{
    qInfo() << message;
}
