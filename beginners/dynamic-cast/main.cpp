/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3FkFiFX
*/

#include <QCoreApplication>
#include <QDebug>

class Vater
{
public:
    explicit Vater(int value): m_value{value}
    {
        // ...
    }

    virtual ~Vater() = default;

protected:
    int m_value {0};
};


class Sohn final : public Vater
{
public:
    explicit Sohn(int alter, const QString &name): Vater{alter}, m_name{name}
    {
        // ...
    }

    const QString& getName() { return m_name;}


protected:
    QString m_name {};
};

Vater* get(bool sohn)
{
    if (sohn) { return new Sohn{20, "John Doe"}; }

    return new Vater{50};
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vater* v {get(true)};

    // Sohn* s {v}; // fail
    Sohn* s {dynamic_cast<Sohn*>(v)}; // successful downcasting, from father to son

    if (s != nullptr) // We always need to check when we use dynamic casting
    {
        qInfo() << " Sohn: " << s->getName() << Q_FUNC_INFO;
    } else
    {
        qWarning() << "Dynamic casting failed! Vater needs to be initialized with Sohn";
    }

    delete v;

    return a.exec();
}
