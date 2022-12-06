#include <iostream>

constexpr int greater(int x, int y) // can be evaluated at compile-time
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int x{9};
    constexpr int y{10};

    constexpr int g{greater(x, y)}; // will be evaluated at compile-time
    std::cout << g << " is greater!\n";

    int a{13};
    std::cout << greater(a, x) << "is greater!\n"; // will be evaluated at runtime,
                                                   // a is not constexpr so the function call is not eligible to be evaluated at compile-time

    std::cout << greater(10, 12) << "is greater!\n"; // might be evaluated at runtime OR compile-time

    return 0;
}