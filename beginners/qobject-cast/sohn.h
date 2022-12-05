#ifndef SOHN_H
#define SOHN_H

#include <QObject>

class Sohn : public QObject
{
    Q_OBJECT
public:
    explicit Sohn(QObject *parent = nullptr);

    QString playToGame() {return "Ich spiele Videospiele";}

signals:

};

#endif // SOHN_H
