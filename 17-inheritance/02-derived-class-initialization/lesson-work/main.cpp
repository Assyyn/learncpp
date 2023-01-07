#include "Apple.h"
#include "Banana.h"
#include "Fruit.h"

#include <iostream>

int main()
{
    const Apple a{"Red delicious", "red", 4.2};
    std::cout << a << '\n';

    const Banana b{"Cavendish", "yellow"};
    std::cout << b << '\n';

    return 0;
}