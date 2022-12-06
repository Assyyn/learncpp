#include <iostream>

auto sum(int x, int y) -> int
{
    return (x + y);
}

// return type is specified after the rest of the function prototype
auto main() -> int
{
    int x{1};
    int y{10};
    std::cout << sum(x, y); // 11

    return 0;
}

// trailing return types are also required for some advanced features of C++ such as lambdas