#include "Fraction.h"

#include <iostream>

void Fraction::reduce()
{
    int gcd{std::gcd(m_numerator, m_denominator)};
    if (gcd) // Make sure we don't try to divide by zero
    {
        m_numerator /= gcd;
        m_denominator /= gcd;
    }
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    os << fraction.m_numerator << '/' << fraction.m_denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
    is >> fraction.m_numerator;

    // Ignore the '/' separator
    is.ignore(std::numeric_limits<std::streamsize>::max(), '/');

    is >> fraction.m_denominator;

    // we overwrote the existing fraction, so we need to reduce again
    fraction.reduce();

    return is;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return {f1.m_numerator * f2.m_numerator,
            f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction& f, int n)
{
    return Fraction{f.m_numerator * n, f.m_denominator};
}

Fraction operator*(int n, const Fraction& f)
{
    // call operator*(Fraction,int) and return its return value
    return {f * n};

    // we could also write that into code directly, thereby making it clear that
    // we are calling an overloaded operator we've defined.
    return {operator*(f, n)};
}