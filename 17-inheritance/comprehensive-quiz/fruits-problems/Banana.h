#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

class Banana : public Fruit
{
public:
    Banana() : Fruit("banana", "yellow") {}
};

#endif