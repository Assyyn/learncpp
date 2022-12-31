#ifndef MONSTER_GENERATOR_H
#define MONSTER_GENERATOR_H

#include "Monster.h"

#include <chrono> // for std::time
#include <random> // for std::mt19937

class MonsterGenerator
{
public:
    static Monster generateMonster();

private:
    static int getRandomNumber(int min, int max);
};

#endif