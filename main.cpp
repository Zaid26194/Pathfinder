#include "pathfinder.h"

#include <QDir>
#include <QString>
#include <iostream>

void setProperCWD()
{
    QString newCWD = "yourCWDHere!"; // TODO!
    if (!QDir::setCurrent(newCWD))
        std::cout << "Could not change the current working directory" << std::endl;
    std::cout << QDir::currentPath().toStdString() << std::endl;
}

int main(int, char *[])
{
    setProperCWD();

    Pathfinder pathfinder;
    pathfinder.run();

    return 0;
}
