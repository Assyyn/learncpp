#include <iostream>

enum Color
{
    red,
    green,
    blue,
    dirty, // HA.HA.
};

int main()
{
    Color shirt{blue};

    // do some work..
    shirt = dirty;

    if (shirt ==
        blue) // we can compare enumerations to enumerators with '==' and '!='
        std::cout << "Your shirt is blue!";
    else if (shirt == dirty)
        std::cout << "Your shirt is dirty!";
    else
        std::cout << "Your shirt is not blue!";

    return 0;
}