#include <iostream>

// An ambiguous match occurs when the compiler finds two or more functions that can be made to match in the same step.
// When this occurs, the compiler will stop matching and issue a compile error stating that it has found an ambiguous function call.

// An example:
namespace A
{
    void print(int x) {}
    void print(double d) {}
}

namespace B
{
    void print(unsigned int x) {}
    void print(float y) {}
}

int main()
{
    A::print(4L); // 4L is of type long
    // no exact match, or numeric promotion.
    // if it is numerically converted to an int, matches print(int)
    // if converted to a double, matches print(double)
    // both are possible, so it is an ambiguous match

    B::print(0);    // int can be converted to both float and unsigned int, resulting in an ambiguous call
    B::print(3.141599); // as a double value cannot be promoted to a float, numeric conversion is required. but it is possible to convert to both u_int and float

    // solutions:
    // 1. define new overloaded function for your required type
    // 2. explicitly cast your arguments to avoid ambiguous calls

    // solution 2 demonstrated below:
    B::print(static_cast<unsigned int>(0)); // perfectly fine
    B::print(static_cast<float>(3.2222149));
    B::print(0U);   // or use literals

    return 0;
}