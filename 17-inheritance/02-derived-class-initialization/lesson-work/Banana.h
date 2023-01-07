// A Banana class, derived from fruit

#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

#include <iostream>

class Banana : public Fruit
{
public:
    Banana(sv name = "", sv color = "") : Fruit(name, color) {}
};

std::ostream& operator<<(std::ostream& os, const Banana& banana)
{
    os << "Banana(" << banana.getName() << ", " << banana.getColor() << ')';
    return os;
}

#endif
