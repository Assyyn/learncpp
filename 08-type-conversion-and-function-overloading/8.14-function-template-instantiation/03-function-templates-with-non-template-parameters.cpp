#include <iostream>
#include <string>

template <typename T>
T someFcn(T x, int y)
{
    return x + static_cast<T>(y);
}

int main()
{
    std::cout << someFcn(3.4,4) << '\n';    // 7.4
    std::cout << someFcn('a',20) << '\n';   // u
    // std::string s {"Hello World!"};
    // std::cout << someFcn(s,30) << '\n'; // it refuses to compile because there is no way to cast a number to string 
}