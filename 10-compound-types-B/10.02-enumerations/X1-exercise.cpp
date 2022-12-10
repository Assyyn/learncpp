// Define an enumerated type named MonsterType to choose between the following
// monster races: orcs, goblins, trolls, ogres, and skeletons.

#include <iostream>
#include <string>

namespace monster
{
enum MonsterType
{
    orc,
    goblin,
    troll,
    ogre,
    skeleton,
};
}

monster::MonsterType getMonsterType()
{
    std::cout << "Choose your Race:\n"
              << "1. Orc\n"
              << "2. Goblin\n"
              << "3. Troll\n"
              << "4. Ogre\n"
              << "5. Skeleton\n";

    for (std::string userInput{};
         std::cin >> userInput,
         userInput[0] =
             tolower(userInput[0]);) // get input until valid input entered
    {
        if (userInput == "orc")
            return monster::orc;
        if (userInput == "goblin")
            return monster::goblin;
        if (userInput == "troll")
            return monster::troll;
        if (userInput == "ogre")
            return monster::ogre;
        if (userInput == "skeleton")
            return monster::skeleton;

        // invalid input
        std::cout << "Invalid Input. Try again\n";
    }

    throw std::runtime_error("Something went wrong.\n");
}

void printRace(monster::MonsterType& Race)
{
    switch (Race)
    {
        case monster::goblin:
            std::cout << "goblin?\n";
            break;
        case monster::orc:
            std::cout << "orc?\n";
            break;
        case monster::skeleton:
            std::cout << "skeleton?\n";
            break;
        case monster::ogre:
            std::cout << "ogre?\n";
            break;
        case monster::troll:
            std::cout << "troll?\n";
            break;
    }
}

int main()
{
    monster::MonsterType userRace{getMonsterType()};
    printRace(userRace);

    monster::MonsterType someAI{monster::troll};
    printRace(someAI);

    return 0;
}
// probably bad code. no excuses available