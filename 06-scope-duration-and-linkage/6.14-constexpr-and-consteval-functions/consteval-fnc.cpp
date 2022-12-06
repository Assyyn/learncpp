// use consteval if you have a function that must run at compile-time for some reason
// eg. performance
#include <iostream>

consteval int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g{greater(5, 6)}; // ok;

    std::cout << greater(5, 6) << " is greater!\n"; // ok;

    int x{5};
    std::cout << greater(x,6) << " is greater!\n";  // error: consteval functions
                                                    // must evaluate at compile-time

    return 0;            
}