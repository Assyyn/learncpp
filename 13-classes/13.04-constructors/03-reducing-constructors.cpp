#include <cassert>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
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

int main()
{
    // the default constructor can now (optionally) take user-provided values as
    // well, while retaining sensible defaults
    Fraction frac;
    Fraction frac1{2, 3};
    Fraction frac2{1};
    Fraction frac3{, 2}; // this is illegal anyway
}