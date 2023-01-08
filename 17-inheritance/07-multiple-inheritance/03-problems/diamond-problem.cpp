#include <iostream>

// https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem
// "diamond problem" (sometimes referred to as the "Deadly Diamond of Death"[6])
// is an ambiguity that arises when two classes B and C inherit from A, and
// class D inherits from both B and C. If there is a method in A that B and C
// have overridden, and D does not override it, then which version of the method
// does D inherit: that of B, or that of C?

class A
{
public:
    int getNumber() const { return 10; }
};

class B : public A
{
public:
    int getNumber() const { return 100; }
};

class C : public A
{
public:
    int getNumber() const { return 1; }
};

class D : public B, public C
{};

// This can be demonstrated by the following example:
int main()
{
    A{}.getNumber(); // fine
    B{}.getNumber(); // fine
    C{}.getNumber(); // fine
    D{}.getNumber(); // error: ambiguous function call

    // turns out it inherits both(under these circumstances):
    D{}.B::getNumber(); // fine
    D{}.C::getNumber(); // fine

    return 0;
}