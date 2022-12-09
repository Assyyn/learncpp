#include <iostream>

int main()
{
    int x{20};   // x is a normal integer variable
    int &ref{x}; // ref is an lvalue reference to an int) that can now be used as an alias for x

    std::cout << x << '\n';
    std::cout << ref << '\n';

    // modifying values through an lvalue reference:

    x = 1;
    std::cout << x << ref << '\n'; // 11

    ref = 10;                      // x now has value 10
    std::cout << x << ref << '\n'; // 1010

    return 0;
}

// A reference is essentially identical to the object being referenced.