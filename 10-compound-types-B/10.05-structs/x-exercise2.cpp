#include <iostream>

/* Create a struct to hold a fraction. The struct should have an integer
 * numerator and an integer denominator member.
 */
struct Fraction
{
    int numerator{0};
    int denominator{1};
};

/* Write a function to read in a Fraction from the user*/
Fraction getFraction()
{
    Fraction temp;

    std::cout << "Numerator: ";
    std::cin >> temp.numerator;

    std::cout << "Denominator: ";
    std::cin >> temp.denominator;

    return temp;
}

/* Write another function to multiply two Fractions together and return the
 * result as a Fraction.*/
Fraction multiplyFractions(const Fraction& x, const Fraction& y)
{
    return {x.numerator * y.numerator, x.denominator * y.denominator};
}

/* Write another function that prints a fraction.*/
std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    os << fraction.numerator << '/' << fraction.denominator;
    return os;
}

int main()
{
    Fraction pi(22, 7);
    Fraction half(1, 2);

    std::cout << "pi*half = " << (multiplyFractions(pi, half)) << '\n';

    Fraction fraction1{getFraction()};
    Fraction fraction2{getFraction()};
    std::cout << "Your fractions multiplied together: "
              << multiplyFractions(fraction1, fraction2) << '\n';

    return 0;
}