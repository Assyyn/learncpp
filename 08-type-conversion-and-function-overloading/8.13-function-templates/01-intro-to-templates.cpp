#include <iostream>

// 'T' can now be replaced with any type and the function works as long as the operations are supported by that type
template <typename T>  // 'typename' or 'class' are the same in this context, but the former is preferred by today's standards
// typenames are most-typically single uppercase characters
T max(T x, T y)
{
    return (x > y ? x : y);
}

int main()
{
    int x{9};
    int y{10};
    std::cout << max<int> (x,y) << '\n';    // 10
    std::cout << max<double> (12.1,12.3) << '\n';    // 12.3

    return 0;
}