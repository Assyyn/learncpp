#ifndef POTIONS_H
#define POTIONS_H

#include <array>
#include <random>
#include <sstream>
#include <string>
#include <string_view>

/* Potion effects chart: [Type: (size(ascending),effect), ...]
 * Health: (small,+(0,1)), (medium,+2), (large,+4), (massive,+(4,6))
 * Strength: (small,+(-1,1)), (medium,+(1,3)), (large,+(3,4)), (massive,+(4,6))
 * Poison: (small,-1), (medium,-2), (large|massive, -(3,6))
 */

class Potion
{
public:
    enum Type
    {
        health,
        strength,
        poison,

        max_types,
    };

    enum Size
    {
        small,
        medium,
        large,
        massive,

        max_size,
    };

private:
    Type m_type{};
    Size m_size{};

public:
    Potion(Type type, Size size) : m_type{type}, m_size{size} {}

    Type getType() const { return m_type; }
    Size getSize() const { return m_size; }

    static std::string_view getTypeName(Type type)
    {
        static constexpr std::array names{"Health", "Strength", "Poison"};

        return names.at(type);
    }

    static std::string_view getSizeName(Size size)
    {
        static constexpr std::array names{"Small", "Medium", "Large",
                                          "Massive"};

        return names.at(size);
    }

    static std::string_view getRarity(Size size)
    {
        static constexpr std::array names{"Common", "Rare", "Epic",
                                          "Legendary"};

        return names.at(size);
    }

    std::string getName() const
    {
        std::stringstream ss;
        ss << getSizeName(m_size) << " potion of " << getTypeName(m_type);

        return ss.str();
    }

    static Potion getRandomPotion()
    {
        return {static_cast<Type>(getRandomNumber(0, max_types - 1)),
                static_cast<Size>(getRandomNumber(0, max_size - 1))};
    }

    int healthEffect() const
    {
        static std::array effect{getRandomNumber(0, 1), 2, 4,
                                 getRandomNumber(4, 6)};

        return effect.at(m_size);
    }

    int strengthEffect() const
    {
        static std::array effect{getRandomNumber(-1, 1), getRandomNumber(1, 3),
                                 getRandomNumber(3, 4), getRandomNumber(4, 6)};

        return effect.at(m_size);
    }

    int poisonEffect() const
    {
        static std::array effect{1, 2, getRandomNumber(3, 6),
                                 getRandomNumber(3, 6)};

        return effect.at(m_size);
    }

    // generate a random number
    static int getRandomNumber(int min, int max)
    {
        std::random_device rd;
        std::seed_seq sseq{rd(), rd(), rd(), rd(), rd()};

        static std::mt19937 mt{sseq};
        return std::uniform_int_distribution{min, max}(mt);
    }
};

#endif