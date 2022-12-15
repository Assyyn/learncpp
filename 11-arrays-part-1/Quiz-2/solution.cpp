// Set up an enum with the names of the following animals: chicken, dog, cat,
// elephant, duck, and snake. Put the enum in a namespace. Define an array with
// an element for each of these animals, and use an initializer list to
// initialize each element to hold the number of legs that animal has.

#include <iostream>

namespace animals
{
enum Animals
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    maxAnimals,
};
}

int main()
{
    using namespace animals;
    int legs[maxAnimals]{2, 4, 4, 4, 2, 0};

    std::cout << "An elephant has " << legs[elephant] << " legs.\n ";

    return 0;
}