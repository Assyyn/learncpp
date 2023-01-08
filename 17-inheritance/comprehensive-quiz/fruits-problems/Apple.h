#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"

class Apple : public Fruit
{
    // so only derived classes can accesss
protected:
    Apple(std::string_view name, std::string_view color) : Fruit(name, color) {}

public:
    Apple(std::string_view color = "red") : Fruit("apple", color) {}
};

#endif