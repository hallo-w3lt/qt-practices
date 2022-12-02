#include <QCoreApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    short radiation_max {118};
    qInfo() << "Max: " << radiation_max;

# if 0
    char radiation = radiation_max; // uncontrolled cast
    qInfo() << "Radiation: " << radiation; // implict casting (insecure)
# endif

# if 1
    int radiation {(int)radiation_max}; // controlled casting
    qInfo() << "Radiation: " << radiation; // explicit casting (secure)
# endif


    return a.exec();
}
