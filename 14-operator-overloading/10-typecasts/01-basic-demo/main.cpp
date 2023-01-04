#include "Cents.h"
#include "Dollars.h"

#include <iostream>

bool equals(int x, int y) { return x == y ? x : y; }

int main()
{
    // implicit type-conversion to Cents, because we don't have a operator<<
    // overload for Dollars(to demonstrate this)
    std::cout << Dollars{100} << '\n';

    // Dollars doesn't have an implicit type-cast to int
    if (equals(static_cast<int>(Dollars{100}), 100))
    {
        std::cout << "$100 was passed in\n";
    }

    // have to be explicit about casting to an int
    // equals(Dollars{100}, 100); // error: cannot convert 'Dollars' to 'int'

    return 0;
}