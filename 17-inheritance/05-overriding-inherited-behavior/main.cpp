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

    // override behavior of inherited function
    void identify() const { std::cout << "I am a Derived\n"; }

    // can call the inherited function still
    void inherited_func() const { Base::identify(); }

    // added functionality(access function)
    int getValue() const { return m_value; }
};

int main()
{
    Derived d{10};
    std::cout << "d has value " << d.getValue();
    d.identify();       // calls Derived::identify()
    d.inherited_func(); // calls Base::identify()
    d.Base::identify(); // calls Base::identify() /* ugly code */

    Base b{1};
    b.identify();

    return 0;
}