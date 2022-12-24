#include <algorithm>
#include <array>
#include <iostream>

/* A default capture (also called a capture-default) captures all variables that
are mentioned in the lambda. Variables not mentioned in the lambda are not
captured if a default capture is used.

To capture all used variables by value, use a capture value of =.
To capture all used variables by reference, use a capture value of &.

*/

int main()
{
    std::array areas{144, 169, 125, 1000};

    int width{};
    int height{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    // the lambda below showcases default capture by value
    auto found{std::find_if(areas.begin(), areas.end(), [=](int knownArea) {
        return (width * height) ==
               knownArea; // width and height are captured by value because they
                          // are mentioned inside the lambda
    })};

    if (found != areas.end())
    {
        std::cout << "Area found :)\n";
    }
    else
        std::cout << "I don't know this area.\n";

    return 0;
}

// we can mix default captures and normal captures
void defaultCaptureCombinations()
{
    int xp{13};
    int level{10};
    char status{'f'};

    [=]() {}; // default capture by value

    auto EventBonus{[=, &xp]() {
        // get bonus xp from event
    }}; // capture level and status by value, xp by reference

    auto killedBossMonster{[&, status]() {
        // do something;
    }}; // capture xp and level by reference, status by value

    auto berserk{[=, &status]() {
        // go berserk, may die
    }};
    // ... and so on
}