#ifndef POINT2D
#define POINT2D

struct Point2D
{
    int x;
    int y;

    bool operator==(const Point2D &p) const { return (x==p.x) && (y==p.y); }
    bool operator!=(const Point2D &p) const { return !((*this)==p); }

    friend bool operator<( const Point2D &a, const Point2D &b );
};

#endif // POINT2D

