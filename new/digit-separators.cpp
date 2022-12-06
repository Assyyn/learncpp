// c++14 and beyond feature: digit-separators in code

#include <iostream>

int main()
{
    constexpr long int veryLargeNum{2'443'122'900}; // (') does not affect our code in any way
    std::cout << veryLargeNum << '\n';
    return 0;
}