#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{numerator}, m_denominator{denominator}
    {}

    // copy constructor
    Fraction(const Fraction& copy) :
        m_numerator{copy.m_numerator}, m_denominator{copy.m_denominator}
    {}

    Fraction& operator=(const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f1);
};

// this does not follow DRY principles, and introduces a significant overhead,
// we have to check for self assignment every time copy assignment is done on
// our class. Fortunately, we can do a little better and use the copy and swap
// idiom, which will be in 02-MyString
Fraction& Fraction::operator=(const Fraction& fraction)
{
    // check for self-assignment
    if (this == &fraction)
        return *this; // do nothing and return itself

    // else, assign to *this
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}

#endif
