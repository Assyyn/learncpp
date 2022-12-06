// do not use c-style-casts*

#include <iostream>

int main()
{
    int x{9};
    int y{5};

    double d{(double)x / y}; // this is c-style-casting
    std::cout << d << '\n';  // 1.8

    double d2{double(x) / y}; // function call-like c-style-cast also allowed
    std::cout << d2 << '\n';  // 1.8

    return 0;
}

// *c-style-casts try to do every type of cast available(dangerous).