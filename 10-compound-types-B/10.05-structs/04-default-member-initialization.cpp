#include <iostream>

struct Fraction
{
    int numerator;
    int denominator{1};
};

// Best Practice: Always provide a default value for all members.
// This avoids instances like f2.numerator in the given example
struct Complex
{
    int realPart{0};
    int imaginaryPart{0};
};

int main()
{
    Fraction f1{};
    Fraction f2;

    // Oops! forgot to value initialize f2!!
    std::cout << f1.numerator << '\n'; // numerator is default-initialized here
    std::cout << f2.numerator << '\n'; // numerator is uninitialized, BAD!

    Complex c1{};
    Complex c2;

    // Complex always has default-initialized members
    std::cout << c1.realPart << c1.imaginaryPart << '\n';
    std::cout << c2.realPart << c2.imaginaryPart << '\n';

    // explicit initialization values take precedence over default value (duh)
    Fraction f3{3, 4};
    Complex c3{-1, 2};

    return 0;
}