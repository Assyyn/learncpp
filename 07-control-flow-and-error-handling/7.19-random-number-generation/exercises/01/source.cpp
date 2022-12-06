#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{myConstants::gravity * seconds * seconds / 2};
    double heightNow{initialHeight - distanceFallen};

    // check whether we've gone under the ground
    //  if so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

bool calculateAndPrintHeight(double initialHeight, int time)
{
    double currentHeight{calculateHeight(initialHeight, time)};
    std::cout << "At " << time
              << " seconds, the ball is at height: " << currentHeight
              << '\n';

    return (currentHeight == 0);
}

int main()
{
    std::cout << "Enter the initial height of the tower in metres: ";
    double initialHeight{};
    std::cin >> initialHeight;

    int seconds{0};

    while ((!calculateAndPrintHeight(initialHeight, seconds)))
        ++seconds;

    return 0;
}