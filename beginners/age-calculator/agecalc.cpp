#include "agecalc.h"

AgeCalc::AgeCalc(QObject *parent)
    : QObject{parent}
{
    // ...
}

int AgeCalc::age() const
{
    return m_age;
}

void AgeCalc::setAge(int inAge)
{
    m_age = inAge;
}

const QString &AgeCalc::name() const
{
    return m_name;
}

void AgeCalc::setName(const QString &inName)
{
    m_name = inName;
}

int AgeCalc::dogYears() const
{
    return m_age * 7;
}

int AgeCalc::catYears() const
{
    return m_age * 9;
}

int AgeCalc::humanYears() const
{
    return m_age;
}
