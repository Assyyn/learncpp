#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{numerator}, m_denominator{denominator}
    {
        assert(denominator != 0);
    }

    // the copy constructor
    Fraction(const Fraction& fraction) :
        m_numerator{fraction.m_numerator}, m_denominator{fraction.m_denominator}
    {
        std::cout << "Called copy constructor\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main()
{
    // Brace initialize a Fraction, calls Fraction(int, int) constructor
    Fraction fiveThirds{5, 3};

    // Brace initialize a Fraction -- calls the Fraction copy constructor
    Fraction fCopy{fiveThirds};

    std::cout << fCopy << '\n';
}

// The copy constructor's parameter must be a reference:if the argument were
// passed by value, then we’d need the copy constructor to copy the argument
// into the parameter of the copy constructor (which would result in an infinite
// recursion).