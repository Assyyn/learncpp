#include "Fraction.h"

void Fraction::print() const
{
    std::cout << m_numerator << '/' << m_denominator << '\n';
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
    // call operator*(Fraction,int)
    return {f * n};
}

void Fraction::reduce()
{
    int gcd{std::gcd(m_numerator, m_denominator)};
    if (gcd) // Make sure we don't try to divide by zero
    {
        m_numerator /= gcd;
        m_denominator /= gcd;
    }
}