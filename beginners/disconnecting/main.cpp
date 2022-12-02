#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <memory>
#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio master;

    // Station* channels[3] {};
    // channels[0] = new Station(&master, 90, "Rock and Roll");
    // channels[1] = new Station(&master, 101, "Jazz");
    // channels[2] = new Station(&master, 87, "News");

    auto channels = std::make_unique<Station*[]>(3);
    channels[0] = new Station(&master, 90, "Rock and Roll");
    channels[1] = new Station(&master, 101, "Jazz");
    channels[2] = new Station(&master, 87, "News");

    master.connect(&master, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        QString line {qtin.readLine().trimmed().toUpper()};

        if ("ON" == line)
        {
            qInfo() << "Turning the radio on";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                master.connect(channel, &Station::send, &master, &Radio::listen);
            }
            qInfo() << "Radio is on";
        }

        if ("OFF" == line)
        {
            qInfo() << "Turning the radio off";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                master.disconnect(channel, &Station::send, &master, &Radio::listen);
            }
            qInfo() << "Radio is off";
        }

        if ("TEST" == line)
        {
            qInfo() << "Testing";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                channel->broadcast("Broadcasting live!");

            }
            qInfo() << "Test complete";
        }

        if ("QUIT" == line)
        {
            qInfo() << "Quitting";
            emit master.quit();

            break;
        }


    } while(true);

    return a.exec();
}
