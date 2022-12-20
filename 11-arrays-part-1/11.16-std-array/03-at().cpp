#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> array{1, 2, 3, 4, 5};

    // at(): does (runtime) bounds checking, and allows random element access
    std::cout << array.at(1) << '\n'; // prints 2
    std::cout << array.at(5) << '\n'; // runtime error is thrown, out-of-range

    return 0;
}