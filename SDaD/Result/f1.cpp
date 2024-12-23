#include <cmath>

struct Point {
    double x;
    double y;

    double distanceTo(const Point& other) const {
        return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y));
    }
};

bool isCorrectTriangle(const Point& a,
                       const Point& b,
                       const Point& c)
{
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ca = c.distanceTo(a);

    if(ab + bc <= ca)
        return false;
    if(ab + ca <= bc)
        return false;
    if(bc + ca <= ab)
        return false;
    return true;
}
