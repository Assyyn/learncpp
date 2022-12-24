#include <functional> // for std::function
#include <iostream>

// As it turns out, lambdas don’t have a type that we can explicitly use. When
// we write a lambda, the compiler generates a unique type just for the lambda
// that is not exposed to us.

int main()
{
    // A regular function pointer. Only works with empty capture-clause
    // (empty [])
    double (*addNumbers1)(double,
                          double){[](double x, double y) { return x + y; }};
    std::cout << "1+2=" << addNumbers1(1, 2) << '\n';

    // Using std::function. The lambda could have non-empty capture clause.
    // Pre-C++17, use std::function<double(double,double)>
    std::function addNumbers2{[](double x, double y) { return x + y; }};
    std::cout << "3+4=" << addNumbers2(3, 4) << '\n';

    // The only way of using the lambda’s actual type is by means of auto. auto
    // also has the benefit of having no overhead compared to std::function.

    // using auto. stores the lambda with its real type
    auto addNumbers3{[](double x, double y) { return x + y; }};
    std::cout << "10+20=" << addNumbers3(10, 20) << '\n';

    return 0;
}