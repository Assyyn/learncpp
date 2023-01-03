#include "Cars.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<Car> cars{{"Toyota", "Corolla"},
                          {"Honda", "Accord"},
                          {"Toyota", "Camry"},
                          {"Honda", "Civic"}};

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}