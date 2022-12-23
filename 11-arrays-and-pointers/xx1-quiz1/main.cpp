/* Question #1

Pretend you’re writing a game where the player can hold 3 types of items: health
potions, torches, and arrows. Create an enum to identify the different types of
items, and an std::array to store the number of each item the player is carrying
(the enumerators are used as indexes of the array). The player should start with
2 health potions, 5 torches, and 10 arrows. Write a function called
countTotalItems() that returns how many items the player has in total. Have your
main() function print the output of countTotalItems() as well as the number of
torches.
*/

#include <array>
#include <iostream>
#include <iterator>
#include <numeric>

enum Item
{
    healthPotion,
    torch,
    arrow,

    maxItems,
};

int countTotalItems(const std::array<int, maxItems>& inventory)
{
    int sum{0};
    sum = inventory[healthPotion] + inventory[torch] + inventory[arrow];

    return sum;
}

int main()
{
    int numPotions{2};
    int numTorch{5};
    int numArrow{10};
    std::array<int, maxItems> inventory{numPotions, numTorch, numArrow};

    std::cout << "Total number of items: " << countTotalItems(inventory) << '\n'
              << "number of torches: " << inventory[Item::torch] << '\n';

    // using std::reduce:
    std::cout << "\nUsing std::reduce:\n";
    int sum{std::reduce(std::next(inventory.begin()), inventory.end(),
                        inventory[0])};
    std::cout << "Total number of items: " << sum << '\n'
              << "number of torches: " << inventory[Item::torch] << '\n';

    return 0;
}