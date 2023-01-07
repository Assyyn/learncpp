// C++ always constructs the “first” or “most base” class first. It then walks
// through the inheritance tree in order and constructs each successive derived
// class.

// Here’s a short program that illustrates the order of creation all along the
// inheritance chain:

#include <iostream>

class A
{
public:
    A() { std::cout << "A\n"; }
};

class B : public A
{
public:
    B() { std::cout << "B\n"; }
};

class C : public B
{
public:
    C() { std::cout << "C\n"; }
};

class D : public C
{
public:
    D() { std::cout << "D\n"; }
};

int main()
{
    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;

    return 0;
}