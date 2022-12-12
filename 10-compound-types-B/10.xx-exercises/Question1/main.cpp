#include <iostream>
#include <string_view>

struct Monster
{
    enum class Type
    {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime,
    };

    Type type{};
    std::string_view name{};
    int health{};
};

constexpr std::string_view MonsterType(const Monster::Type type)
{
    using enum Monster::Type;
    switch (type)
    {
        case ogre:
            return "Ogre";
        case dragon:
            return "Dragon";
        case orc:
            return "Orc";
        case giantSpider:
            return "Giant spider";
        case slime:
            return "Slime";
        default:
            return "???";
    }
}

void printMonster(const Monster& monster)
{
    std::cout << "This " << MonsterType(monster.type) << " is named "
              << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
    Monster tommy{Monster::Type::ogre, "Tommy", 140};
    printMonster(tommy);

    Monster blurp{Monster::Type::ogre, "Blurp", 23};
    printMonster(blurp);

    return 0;
}