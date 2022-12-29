// Make any member function that does not modify the state of the class object
// const, so that it can be called by const objects.

#include <iostream>

// we can make member functions const as shown in the example
class Simple
{
private:
    int m_value{};

public:
    Simple() = default;

    // now every Simple object can use getValue()
    int getValue() const
    {
        return m_value;
    }

    // const functions defined outside of class definition :
    void print() const;
};

// const applied in both the function declaration and definition
void Simple::print() const
{
    std::cout << m_value << '\n';
}

int main()
{
    Simple x{};
    x.getValue();
    x.print();

    // these const functions now work with const objects
    const Simple y{};
    y.getValue();
    y.print();
}