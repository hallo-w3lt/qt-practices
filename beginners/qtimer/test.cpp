#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    m_count = 0;
    connect(&m_timer, &QTimer::timeout, this, &Test::timeout);
    m_timer.start();
    m_timer.setInterval(1000);
}

void Test::timeout()
{
    qInfo() << "Test!";
    if (++m_count >= 3)
    {
        m_timer.stop();
        qInfo() << "Done!";
    }
}
