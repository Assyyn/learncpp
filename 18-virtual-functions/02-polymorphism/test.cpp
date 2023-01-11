// some observations?

#include <iostream>

class Base
{
public:
    virtual char getSymbol() const { return 'B'; }
    virtual double half() const { return 1.0 / 2; }
};

class Derived : public Base
{
public:
    // an override: completely `override` inherited (virtual)function(s)
    char getSymbol() const override { return Base::getSymbol() + 'D'; }
    double half() const { return Base::half() + 1.0 / 2; }
};

int main()
{
    Derived d{};
    Base* b{&d};
    std::cout << b->getSymbol();

    Base* collection[]{&d, b}; // an array of pointers to @Base objects

    std::cout << collection[0]->getSymbol();

    std::cout << d.half();
}

// Output: DD