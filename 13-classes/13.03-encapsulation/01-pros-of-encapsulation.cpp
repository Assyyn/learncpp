#include <iostream>
#include <string>
#include <vector>

// encapsulation provides us with an interface such that we can use the class
// without really having to understand everything about its implementation,
// like the standard library classes std::vector and std::string
void doSomething()
{
    std::string s{
        "I don't really need to know if this gets converted into a c-style string first, or any of the implementation details of std::string"};

    // There is no need for me to actually know how a std::vector allocates
    // memory or frees it, it simply does and is usually not a thing to be
    // explicitly thinking about
    std::vector<int> a{1, 2};
}

// Encapsulation gives us the ability to change how classes are implemented
// without breaking all of the programs that use them.
class A
{
public:
    int m_Value{};
};

// version 2: made small changes
class Av2
{
public:
    // changed data-type to double, renamed value to m_value from m_Value
    double m_value{};
};

void testA()
{
    // while this works fine, what if we want to change the type of m_value, or
    // rename it? It would break our program(which could as well be over 1000
    // lines already) as well as everywhere we used A!
    A x;
    x.m_Value = 30;
    std::cout << x.m_Value;
    Av2 x2;
    x2.m_Value = 30;        // -> this code is now broken
    std::cout << x.m_Value; // oops! we renamed it in this version of code
}

// rewriting class A as B: encapsulating m_value ;)
class B
{
private:
    int m_value{};

public:
    int getValue()
    {
        return m_value;
    }

    void setValue(int x)
    {
        m_value = x;
    }
};

class Bv2
{
private:
    // changed data type of m_value and renamed it to m_Value
    double m_Value{};

public:
    void setValue(double x)
    {
        m_Value = x;
    }

    double getValue()
    {
        return m_Value;
    }
};

void testB()
{
    B b;
    b.setValue(10);
    std::cout << b.getValue() << '\n';

    // note: we made the same changes as to class 'A', but the code has remained
    // functional(as in working, not the paradigm)!
    Bv2 b2;
    b2.setValue(10);
    std::cout << b2.getValue() << '\n';
}

// Benefit: encapsulated classes help protect your data and prevent misuse

// misuse-prone
class IntArray
{
public:
    int m_array[10];
};

// IntArrayV2: provide an interface to access the array
class IntArrayV2
{
private:
    int m_array[10];

public:
    int at(int index)
    {
        // now it conveniently throws an error, preventing access out of the
        // memory it owns
        if (index < 0 || index > 9)
            throw std::runtime_error("IntArrayV2.at() out-of-bounds error");

        return m_array[index];
    }
};

// nothing stops someone from 'un'knowingly trying to access memory that
// IntArray does not own
void accessArray()
{
    IntArray array;
    std::cout << array.m_array[20] << '\n'; // hmm..

    IntArrayV2 arrayV2;
    std::cout << arrayV2.at(20) << '\n';
}