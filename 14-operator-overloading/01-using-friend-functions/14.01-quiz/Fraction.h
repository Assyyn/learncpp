#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric> // for std::gcd, returns the Greatest Common Divisor between 2 integers(?)

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{numerator}, m_denominator{denominator}
    {
        // will always reduce newly created Fraction objects, which is what our
        // overloads of operator* do.
        reduce();
    }

    void print() const;

    // overload operator* for Fraction*Fraction and Fraction*int
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int n);
    friend Fraction operator*(int n, const Fraction& f);

    // reduce a fraction to lowest terms
    void reduce();
};

#endif