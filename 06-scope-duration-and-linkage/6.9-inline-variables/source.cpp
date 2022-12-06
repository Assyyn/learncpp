#include "constants.h"  //contains the inline variables to be used in the project

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double r;
    std::cin >> r;

    double Area = constants::pi* r*r;
    std::cout << "Area: " << Area << '\n';

    return 0;
}