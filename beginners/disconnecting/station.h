#ifndef STATION_H
#define STATION_H

#include <QObject>

class Station : public QObject
{
    Q_OBJECT

public:
    explicit Station(QObject *parent = nullptr, int channel = 0, QString name = "unknown")
        : m_channel{channel}, m_name{name}
    {
        // ...
    };

signals:
    void send(int channel, QString name, QString message);

 public slots:
    void broadcast(QString message);

private:
    int m_channel {0};
    QString m_name {};


};

#endif // STATION_H
