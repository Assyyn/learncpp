// It can sometimes be useful to have a class member function return the object
// it was working with as a return value

#include <iostream>

// a simple example:
class Calc
{
private:
    int m_value{};

public:
    Calc& add(int x)
    {
        m_value += x;
        return *this;
    }

    Calc& mult(int x)
    {
        m_value *= x;
        return *this;
    }

    Calc& div(int x)
    {
        m_value /= x;
        return *this;
    }

    Calc& sub(int x)
    {
        m_value -= x;
        return *this;
    }

    int getValue()
    {
        return m_value;
    }
};

int main()
{
    Calc x{};
    // ((((0+5)-10)*2)/5) = -2
    x.add(5).sub(10).mult(2).div(5); // chainable functions!

    std::cout << x.getValue() << '\n';
}