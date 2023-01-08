#include <iostream>

class Base
{
protected:
    int m_value{};

public:
    Base(int value) : m_value{value} {}

    void identify() const { std::cout << "I am a Base\n"; }
};

// Assume `Base` is in a 3rd party library, and cannot be modified
class Derived : public Base
{
public:
    Derived(int value) : Base(value) {}

    // added functionality(access function)
    int getValue() const { return m_value; }
};

int main()
{
    Derived d{10};
    std::cout << "d has value " << d.getValue();

    return 0;
}