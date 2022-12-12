#include <iostream>
#include <string>

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name;
    Paw paw{};
};

int main()
{
    Animal cat{"Cat", {4}};

    Animal* ptr{&cat};

    // ptr is a pointer to cat
    // paw is a Paw
    std::cout << "A cat has: " << (ptr->paw).claws << '\n';

    return 0;
}