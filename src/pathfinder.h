#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <vector>

#include "point2d.h"

class Pathfinder
{
public:
    Pathfinder();
    void runCMD();
    bool solveFile( const std::string &path, std::vector<Point2D> &solution);
    bool perfect;
    std::vector<Point2D> solution;
};

#endif // PATHFINDER_H
