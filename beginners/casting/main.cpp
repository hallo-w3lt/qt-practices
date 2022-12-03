#include <QCoreApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    short radiation_max {118};
    qInfo() << "Max: " << radiation_max;

# if 0
    char radiation = radiation_max; // uncontrolled cast
    qInfo() << "Radiation: " << radiation; // implict casting
# endif

# if 0
    int radiation {(int)radiation_max}; // controlled casting
    qInfo() << "Radiation: " << radiation; // explicit casting style-c
# endif

# if 1
    int radiation {static_cast<int>(radiation_max)}; // controlled casting (secure)
    qInfo() << "Radiation: " << radiation; // explicit casting
# endif


    return a.exec();
}
