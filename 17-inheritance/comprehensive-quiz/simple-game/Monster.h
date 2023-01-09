#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

#include <array>
#include <random>

class Monster : public Creature
{
public:
    // Monster Types have attributes, we will implement a lookup table
    enum class Type
    {
        dragon,
        orc,
        slime,

        max_types,
    };

private:
    // (static)lookup table
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature,
                                static_cast<std::size_t>(Type::max_types)>
            monsterData{{{"dragon", 'D', 20, 4, 100},
                         {"orc", 'O', 4, 2, 25},
                         {"slime", 'S', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type) : Creature(getDefaultCreature(type)) {}

    static inline Monster getRandomMonster();
};

// generate a random number
int getRandomNumber(int min, int max)
{
    std::random_device rd;
    std::seed_seq sseq{rd(), rd(), rd(), rd(), rd()};

    static std::mt19937 mt{sseq};
    return std::uniform_int_distribution{min, max}(mt);
}

Monster Monster::getRandomMonster()
{
    int num{getRandomNumber(0, static_cast<int>(Type::max_types) - 1)};
    return Monster(static_cast<Type>(num));
}

#endif