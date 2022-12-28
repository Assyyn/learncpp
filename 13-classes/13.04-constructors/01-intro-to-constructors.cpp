#include <iostream>

// A constructor is a special kind of class member function that is
// automatically called when an object of that class is created. Constructors
// are typically used to initialize member variables of the class to appropriate
// user-provided values, or to do any setup steps necessary for the class to be
// used (e.g. open a file or database).

// Default constructors and default initialization
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
    // value initialize if you don't know whether the member variables have
    // default initializers or whether the class has a default constructor
    Fraction frac{}; // calls Fraction's default constructor

    // it is perfectly fine to default-initialize Fraction here
    Fraction frac2;

    // both these statements produce the same output
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';
    std::cout << frac2.getNumerator() << '/' << frac2.getDenominator() << '\n';

    return 0;
}