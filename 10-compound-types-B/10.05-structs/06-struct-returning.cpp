#include <iostream>

struct Point3d // represents a point in 3d space
{
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

// option 1: create a named object, and return it
Point3d origin()
{
    Point3d temp{0.0, 0.0, 0.0};
    return temp;
}

// option 2: return without actually making a named object:
Point3d getZeroPoint()
{
    return {0.0, 0.0, 0.0};
}