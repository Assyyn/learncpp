#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) :
        m_x{x}, m_y{y}, m_z{z}
    {}

    double getX() { return m_x; }
    double getY() { return m_y; }
    double getZ() { return m_z; }

    // pass Point by const reference to allow rvalues to also be printed this
    // way
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    // drop const here because we take input
    friend std::istream& operator>>(std::istream& is, Point& point);
};

#endif