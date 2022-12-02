#include <QCoreApplication>
#include <QDebug>

void print(QString &source, int option = 1)
{
    if (1 == option) { qInfo() << "info: Hi, " << source << Q_FUNC_INFO; return; }
    if (2 == option) { qWarning() << "warning: Hi, " << source << Q_FUNC_INFO; return; }
    if (3 == option) { qCritical() << "critial: Hi, " << source << Q_FUNC_INFO; return; }

    qFatal("fatal: this is not fine!");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString me {"John Doe"};
    print(me, 1);

    return a.exec();
}
