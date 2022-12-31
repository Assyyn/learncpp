// contains the main() function. Program execution begins and ends here

#include "Monster.h"          // for class Monster
#include "MonsterGenerator.h" // for class MonsterGenerator

int main()
{
    for (int count{0}; count < 10; ++count)
    {
        MonsterGenerator::generateMonster().print();
        std::cin.get(); // wait for user to press enter
    }

    return 0;
}