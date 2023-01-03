#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "Point(" << p.m_x << ',' << p.m_y << ',' << p.m_z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.m_x;
    is >> p.m_y;
    is >> p.m_z;

    return is;
}