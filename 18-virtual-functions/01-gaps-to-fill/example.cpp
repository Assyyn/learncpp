// Pointers and references to the base class of derived objects, and their
// limitations

#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name) : m_name{name} {}

    // To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name) : Animal{name} {}

    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name) : Animal{name} {}

    std::string_view speak() const { return "Woof"; }
};

int main()
{
    const Cat fred{"Fred"};
    const Cat misty{"Misty"};
    const Cat zeke{"Zeke"};

    const Dog garbo{"Garbo"};
    const Dog pooky{"Pooky"};
    const Dog truffle{"Truffle"};

    // Set up an array of pointers to animals, and set those pointers to our Cat
    // and Dog objects Note: to_array requires C++20 support
    const auto animals{std::to_array<const Animal*>(
        {&fred, &garbo, &misty, &pooky, &truffle, &zeke})};

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty,
    // &pooky, &truffle, &zeke };

    // Animal* cannot access functions of Cat and Dog,
    // so every animal will say "???", which is really not what we desired
    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}