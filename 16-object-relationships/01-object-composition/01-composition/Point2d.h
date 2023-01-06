#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

// the world is assumed to be made up of discrete squares
// a simple class to handle points in a discrete environment
class Point2d
{
private:
    int m_x{};
    int m_y{};

public:
    Point2d() : m_x{0}, m_y{0} {}
    Point2d(int x, int y) : m_x{x}, m_y{y} {}

    friend std::ostream& operator<<(std::ostream& os, const Point2d& p);

    void setPoint(int x, int y);
};

std::ostream& operator<<(std::ostream& os, const Point2d& p)
{
    os << '(' << p.m_x << ", " << p.m_y << ')';
    return os;
}

void Point2d::setPoint(int x, int y)
{
    m_x = x;
    m_y = y;
}

#endif