#ifndef VATER_H
#define VATER_H

#include <QObject>

class Vater : public QObject
{
    Q_OBJECT
public:
    explicit Vater(QObject *parent = nullptr);

    QString getABeer() { return "Ich trinke ein Bier";}

    virtual ~Vater() = default;

signals:

};

#endif // VATER_H
