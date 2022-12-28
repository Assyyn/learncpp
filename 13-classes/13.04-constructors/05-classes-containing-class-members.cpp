#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B
{
private:
    A m_a; // B contains A as a member variable

public:
    B()
    {
        std::cout << "B\n";
    }
};

int main()
{
    B b;
    // B is to be constructed:
    // as m_a is of type A, it gets created first, which calls its default
    // constructor, prints 'A' to the console
    // then B is constructed, prints 'B' in next line

    return 0;
}