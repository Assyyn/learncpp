// The process of omitting certain copy (or move) steps for performance purposes
// is called elision

#include <iostream>

// consider a trivial class with a copy constructor:
class Trivial
{
private:
    int m_value{};

public:
    Trivial(int value = 0) : m_value{value} {}

    // copy constructor
    Trivial(const Trivial& trivial) : m_value{trivial.m_value}
    {
        std::cout << "Copy constructor called\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Trivial& trivial)
    {
        os << trivial.m_value;
        return os;
    }
};

int main()
{
    // the compiler will(most likely) omit the creation of the copy since this
    // statement is the same as `Trivial x{2};`, in which case the copy
    // constructor has been elided
    Trivial x{Trivial{2}};
    std::cout << x << '\n';

    Trivial y{x}; // copy constructor is called
    std::cout << y << '\n';

    return 0;
}