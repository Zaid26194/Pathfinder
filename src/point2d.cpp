#include "point2d.h"

bool operator<(const Point2D &a, const Point2D &b )
{
    return (a.x < b.x) ? true : ((a.x == b.x) && a.y < b.y);
}
