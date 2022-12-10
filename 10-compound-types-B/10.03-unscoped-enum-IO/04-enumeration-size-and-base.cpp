#include <iostream>

// The compiler is responsible to determine how much memory to allocate for an
// enum variable. Most often, it will make enum variables the same size as
// an int.

// We can, however, specify a different underlying type
enum Color : std::uint8_t // Color enums now have size of 1byte
{
    black,
    red,
    blue,
};

int main()
{
    std::cout << sizeof(black) << '\n'; // prints '1' as in 1byte

    return 0;
}