#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
protected:
    std::string m_name;
    char m_symbol{};
    int m_health{};
    int m_baseDamage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int baseDamage,
             int gold) :
        m_name{name},
        m_symbol{symbol}, m_health{health}, m_baseDamage{baseDamage}, m_gold{
                                                                          gold}
    {}

    std::string_view getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_baseDamage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int by) { m_health -= by; }
    bool isDead() const { return m_health <= 0; }
    void addGold(int amount) { m_gold += amount; }
};

#endif