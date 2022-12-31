#include "Monster.h"

Monster::Monster(Type type, std::string_view name, std::string_view roar,
                 int hitPoints) :
    m_type{type},
    m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
{}

std::string_view Monster::getTypeString() const
{
    using namespace std::string_view_literals;
    using enum Type;
    switch (m_type)
    {
        case dragon:
            return "dragon"sv;
        case goblin:
            return "goblin"sv;
        case ogre:
            return "ogre"sv;
        case orc:
            return "orc"sv;
        case skeleton:
            return "skeleton"sv;
        case troll:
            return "troll"sv;
        case vampire:
            return "vampire"sv;
        case zombie:
            return "zombie"sv;
        default:
            return "???"sv;
    }
}

void Monster::print() const
{
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints
              << " hit points and says " << m_roar << ".\n";
}