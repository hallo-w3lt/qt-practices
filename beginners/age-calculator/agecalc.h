#ifndef AGECALC_H
#define AGECALC_H

#include <QObject>

class AgeCalc : public QObject
{
    Q_OBJECT
public:
    explicit AgeCalc(QObject *parent = nullptr);

    int age() const;
    void setAge(int inAge);

    const QString &name() const;
    void setName(const QString &inName);

    int dogYears() const;
    int catYears() const;
    int humanYears() const;

signals:

private:
    int m_age {0};
    QString m_name {};



};

#endif // AGECALC_H
