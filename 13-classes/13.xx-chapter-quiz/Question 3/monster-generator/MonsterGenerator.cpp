#include "MonsterGenerator.h"

Monster MonsterGenerator::generateMonster()
{
    Monster::Type type{getRandomNumber(
        0, static_cast<int>(Monster::Type::max_monster_types) - 1)};
    int hitPoints{getRandomNumber(1, 100)};

    constexpr static std::string_view s_names[6]{
        "Kyuubi", "Oni", "Kronos", "Betelgeuse", "Fafnir", "Eil"};

    constexpr static std::string_view s_roars[6]{
        "*screech*", "*howl*", "*growl*", "*rattle*", "*bleep*", "*nothing*"};

    return Monster{type, s_names[getRandomNumber(0, 5)],
                   s_roars[getRandomNumber(0, 5)], hitPoints};
}

int MonsterGenerator::getRandomNumber(int min, int max)
{
    // seed our random number generator with the current time
    static std::mt19937 mersenne{
        static_cast<std::mt19937::result_type>(std::time(nullptr))};

    // distribute results from our RNG between min and max (inclusive)
    return std::uniform_int_distribution{min, max}(mersenne);
}