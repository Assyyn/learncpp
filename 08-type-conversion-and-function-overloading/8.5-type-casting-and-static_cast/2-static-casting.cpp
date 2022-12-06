#include <iostream>

int main()
{
    int x{9};
    int y{5};

    double d{static_cast<double>(x) / y};   // favor when: converting a value from one type to another
    std::cout << d << '\n';  // 1.8

    return 0;
}

// provides compile-time type checking, making it harder to make inadvertent error