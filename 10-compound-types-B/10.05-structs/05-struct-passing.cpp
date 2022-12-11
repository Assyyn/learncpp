#include <iostream>

struct Fraction
{
    int numerator{0};
    int denominator{1};
};

// passing by reference
void printFraction(const Fraction& fraction)
{
    std::cout << "Fraction: " << fraction.numerator << '/'
              << fraction.denominator << '\n';
}

int main()
{
    // we can use {10,3} as it fits a 'Fraction' struct definition
    printFraction({10, 3});

    // or just pass a Fraction object:
    Fraction f{2, 3};
    printFraction(f);

    return 0;
}