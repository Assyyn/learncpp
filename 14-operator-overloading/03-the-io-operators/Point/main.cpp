#include "Point.h"

#include <iostream>
#include <sstream>

int main()
{
    Point p{};
    std::cout << p << ' ' << Point{3, 4, 5} << '\n';

    // you don't need to know this right now.
    // recreating a scenario where user enters those values to std::cin
    std::istringstream dummyIn("1.2 -1.4 3.59");
    dummyIn >> p;

    std::cout << p; // prints `Point(1.2,-1.4,3.59)`

    return 0;
}