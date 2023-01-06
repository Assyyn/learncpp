// https://www.learncpp.com/cpp-tutorial/composition/ to read up on composition

#include "Monster.h"
#include "Point2d.h"
// A good rule of thumb is that each class should be built to accomplish a
// single task. That task should either be the storage and manipulation of some
// kind of data (e.g. Point2D, std::string), OR the coordination of its members
// (e.g. Monster). Ideally not both.

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a name for your monster: ";
    std::string name;
    std::cin >> name;
    Monster monster{name, {4, 7}};

    while (true)
    {
        // print the monster's name and location
        std::cout << monster << '\n';

        std::cout << "Enter new X location for monster (-1 to quit): ";
        int x{0};
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for monster (-1 to quit): ";
        int y{0};
        std::cin >> y;
        if (y == -1)
            break;

        monster.move_to(x, y);
    }

    return 0;
}