#include <cassert>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator()
    {
        return m_numerator;
    }
    int getDenominator()
    {
        return m_denominator;
    }
    double getValue()
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};

// we can use either list-initialization or direct initialization to construct
// our objects:
//--> prefer list initialization unless something else could cause conflict
Fraction fracList{1, 2};
Fraction fracDirect(1, 2);

// avoid trying to copy initialize with classes as they may be inefficient
Fraction fracCopy = 8; // invokes Fraction(8,1)
Fraction fracCopy2 = Fraction{10};