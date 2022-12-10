/* Define an enum class named Animal that contains the following animals: pig,
 * chicken, goat, cat, dog, duck.
 *
 * Write a function named getAnimalName() that takes an Animal parameter and
 * uses a switch statement to return the name for that animal as a
 * std::string_view (or std::string if you’re using C++14).
 *
 * Write another function named printNumberOfLegs() that uses a switch statement
 * to print the number of legs each animal walks on. Make sure both functions
 * have a default case that prints an error message.
 *
 * Call printNumberOfLegs() from main() with a cat and a chicken. Your output
 * should look like this: A cat has 4 legs. A chicken has 2 legs.
 * */

#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view
    getAnimalName(const Animal animal) // return animal name
{
    using enum Animal;
    switch (animal)
    {
        case pig:
            return "pig";
        case chicken:
            return "chicken";
        case goat:
            return "goat";
        case cat:
            return "cat";
        case dog:
            return "dog";
        case duck:
            return "duck";
        default:
            return "???";
    }
}

void printNumberOfLegs(Animal animal)
// print number of legs the animal walks on
{
    using enum Animal;
    int legs{};
    switch (animal)
    {
        case dog:
        case cat:
        case pig:
        case goat:
            legs = 4;
            break;
        case chicken:
        case duck:
            legs = 2;
            break;
        default:
            std::cout << "???. unknown Animal...\n";
            return; // early return
    }
    std::cout << "A " << getAnimalName(animal) << " has " << legs << " legs\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);

    printNumberOfLegs(Animal::chicken);

    return 0;
}

// done :tick: