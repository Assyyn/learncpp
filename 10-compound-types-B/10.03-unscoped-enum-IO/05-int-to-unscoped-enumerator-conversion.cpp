#include <iostream>

enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

// in C++17, if an unscoped enum has a specified base, the compiler allows
// initialization of said enum using an integral value(but not assignment)
enum Computer : int
{
    laptop,
    desktop,
    palmtop,
};

int main()
{
    /*
    Pet pet{2}; // compile error:
                // integer value 2 will not implicitly convert to a Pet
    pet = 3;    // compile error:
                // integer value 3 won't implicitly convert to a Pet
    */

    // we can work around this using (1): static_cast
    Pet pet{static_cast<Pet>(2)}; // now 2 can represent pig
    pet = static_cast<Pet>(4);    // our pet became a whale!

    // we can initialize enum 'Computer' using an integral value:
    Computer work{1}; // initialized to 'desktop'

    // (but does not allow assignment)
    work = 2; // compile error: cannot assign with an integer

    return 0;
}