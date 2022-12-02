#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    // ...
}

const QString &Test::getMessage() const
{
    return message;
}

void Test::setMessage(const QString &inMessage)
{
    if (message == inMessage) {return;}

    message = inMessage;
    emit messageChanged(message);
}
