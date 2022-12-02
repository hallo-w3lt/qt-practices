#include <QCoreApplication>
#include <QVariant>

#include "test.h"
#include "watcher.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test tester;
    Watcher watcher;

    QObject::connect(&tester, &Test::messageChanged, &watcher, &Watcher::messageChanged);

    tester.setProperty("message", QVariant("Hello from main"));
    tester.setMessage("Hallo");

    return a.exec();
}
