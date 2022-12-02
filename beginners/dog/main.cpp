#include <QCoreApplication>

#include "dog.h"
#include "owner.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Owner owner;
    Dog dog;

# if 1
    QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats); // Qt::AutoConnection
# endif

# if 0
    for (int i {0}; i < 10; ++i)
    {
        // QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats, Qt::QueuedConnection);
        QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats, Qt::UniqueConnection);
    }
# endif

    owner.giveSnacks();

    return a.exec();
}
