// Apple class, derived from Fruit

#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"

#include <iostream>

class Apple : public Fruit
{
private:
    double m_fiber{};

public:
    Apple(sv name = "", sv color = "", double fiber = 0.0) :
        Fruit(name, color), m_fiber{fiber}
    {}

    double getFiber() const { return m_fiber; }
};

std::ostream& operator<<(std::ostream& os, const Apple& apple)
{
    os << "Apple(" << apple.getName() << ", " << apple.getColor() << ", "
       << apple.getFiber() << ')';
    return os;
}

#endif