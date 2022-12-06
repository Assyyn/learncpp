#include <iostream>

template <typename T>
T max(T x, T y) // this template will not be able to resolve calls like: max(3,2.4) ie, calls with multiple types
{
    return (x > y ? x : y);
}

// a better way, using multiple-template-type-parameters
template <typename T, typename U>
T min(T x, U y)
{
    return (x < y ? x : y);
}
// a problem:
// if we call min(3,4.3), it returns an int. BUT there is implicit type conversion of 3 to 'double' during the comparision
// in cases like this, the resulting double after comparision is then undergo a narrow conversion to int,
// which will produce a warning and possible loss of data

// an even better way: using auto to let the compiler deduce our return type from the return statement
template <typename T, typename U>
auto divide(T x, U y)
{
    return x / y;
}
// a call like divide(3.9,2) will now return a double

int main()
{
    std::cout << divide(3.9, 2) << '\n'; // 1.95

    return 0;
}