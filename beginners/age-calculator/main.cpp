#include <QCoreApplication>
#include <QDebug>
#include "agecalc.h"

void print(const AgeCalc &calc)
{
    qInfo() << "name:" << calc.name() << " Human age: " << calc.humanYears();
    qInfo() << "name:" << calc.name() << " Dog age: " << calc.dogYears();
    qInfo() << "name:" << calc.name() << " Cat age: " << calc.catYears();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AgeCalc agec;
    agec.setName("John Doe");
    agec.setAge(24);

    print(agec);

    return a.exec();
}
