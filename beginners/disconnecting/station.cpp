#include "station.h"

// Station::Station(QObject *parent, int channel, QString name)
// {
//     m_channel = channel;
//     m_name = name;
// }

void Station::broadcast(QString message)
{
    emit send(m_channel, m_name, message);
}
