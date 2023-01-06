#ifndef MONSTER_H
#define MONSTER_H

#include "Point2d.h"

#include <iostream>
#include <string>
#include <string_view>

// m_name and m_location are a 'part-of' Monster
// This Monster is also a composition of its parts. The monster’s name and
// location have one parent, and their lifetime is tied to that of the Monster
// they are part of.
class Monster
{
private:
    std::string m_name;
    Point2d m_location;

public:
    Monster(std::string_view name, const Point2d& location) :
        m_name{name}, m_location{location}
    {}

    friend std::ostream& operator<<(std::ostream& os, const Monster& m);

    void move_to(int x, int y) { m_location.setPoint(x, y); }
};

std::ostream& operator<<(std::ostream& os, const Monster& m)
{
    os << m.m_name << " is at " << m.m_location;
    return os;
}

#endif