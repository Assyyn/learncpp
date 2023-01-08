// Source: https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/

// In C++, it is not possible to remove or restrict functionality from a base
// class other than by modifying the source code. However, in a derived class,
// it is possible to hide functionality that exists in the base class, so that
// it can not be accessed through the derived class. This can be done simply by
// changing the relevant access specifier.

// For example, we can make a public member private :

#include <iostream>

class Base
{
private:
    int m_value{};

public:
    Base(int value) : m_value{value} {}

    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value) : Base{value} {}

    int getValue() = delete; // mark this function as inaccessible
};

int main()
{
    Derived derived{7};

    // The following won't work because getValue() has been deleted!
    std::cout << derived.getValue();

    // We can call the Base::getValue() function directly
    std::cout << derived.Base::getValue();

    // Or we can upcast Derived to a Base reference and getValue() will resolve
    // to Base::getValue()
    std::cout << static_cast<Base&>(derived).getValue();

    // If using the casting method, we cast to a Base& rather than a Base to
    // avoid making a copy of the Base portion of derived.

    return 0;
}
