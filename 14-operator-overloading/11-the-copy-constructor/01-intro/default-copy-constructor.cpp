// A copy constructor is a special type of constructor used to create a new
// object as a copy of an existing object (of the same type)

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

    // Brace initialize a Fraction -- with what constructor?
    Fraction fCopy{fiveThirds};
    // the compiler will create a default copy constructor if one isn't already
    // provided

    std::cout << fCopy << '\n';
}
