#include <iostream>

consteval auto compileTime(auto value)
{
    return value;
}

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greater(5, 6) << '\n'; // may execute at compile-time

    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time

    int x{5};
    std::cout << greater(x,6) << '\n';  // flexible, no errors here. will execute at run-time

    return 0;
}