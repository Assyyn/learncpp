#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << max<int>(2, 4) << '\n'; // creates a max<int>(int,int) function from our template to use
                                         // this is called function template instantiation
    std::cout << max<double>(3.0,4.2) << '\n'; // instantiated max<double>(double,double)                                        
}