#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Player.h"
#include "Potions.h"

#include <iostream>
#include <string>
#include <string_view>

class Player : public Creature
{
private:
    int m_level{1};

public:
    Player(std::string_view name) : Creature(name, '@', 10, 1, 0) {}

    void levelUp()
    {
        ++m_level;
        ++m_baseDamage;
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }

    // applies a Potion's effect to the player
    void drinkPotion(const Potion& potion)
    {
        switch (potion.getType())
        {
            case Potion::health:
                m_health += potion.healthEffect();
                std::cout << "HP increased to " << m_health << "(+"
                          << potion.healthEffect() << ").";
                break;
            case Potion::strength:
                m_baseDamage += potion.strengthEffect();
                std::cout << "DMG increased to " << m_baseDamage << "(+"
                          << potion.strengthEffect() << ").";
                break;
            case Potion::poison:
                reduceHealth(potion.poisonEffect());
                std::cout << "HP decreased to " << m_health << "(-"
                          << potion.poisonEffect() << ").";
                break;
            default:
                std::cout << "attempt to drink potion that does not exist\n";
        }
    }
};

#endif