#include <QCoreApplication>
#include <QDebug>

void test_by_ref(QString &source)
{
    qInfo() << source << " by copy";
}

void test_by_copy(QString source)
{
    qInfo() << source << " by ref";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name {"Bryan Cairns courses are great!"};
    qInfo() << name;
    qInfo() << name.mid(1,3);
    qInfo() << name.insert(0,"Mr. ");
    qInfo() << name.split(" ");

    int index = name.indexOf(" ");
    if(index > -1)
    {
        qInfo() << name.remove(0, index).trimmed();
    }

    QString title {"Teacher"};
    QString full {name.trimmed() + " " + title};

    qInfo() << full;
    qInfo() << full.toUtf8();

    test_by_copy(full);
    test_by_ref(full);

    return a.exec();
}
