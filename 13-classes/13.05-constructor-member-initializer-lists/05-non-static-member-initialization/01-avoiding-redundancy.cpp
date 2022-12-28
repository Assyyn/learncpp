// Rule:
// Favor use of non-static member initialization to give default values for your
// member variables.

#include <iostream>

// the following example shows how non-static member initialization can help
// reduce redundancy(instead of having to supply default parameters) in our
// constructors:
class Rectangle
{
private:
    double m_length{1.0};
    double m_width{1.0};

public:
    Rectangle() = default; // default values for m_length and m_width are used

    Rectangle(double length, double width) : m_length{length}, m_width{width}
    {
        // m_length and m_width are initialized by the constructor (the default
        // values aren't used)
    }

    Rectangle(double length) : m_length{length}
    {
        // m_length is initialized by the constructor.
        // m_width's default value (1.0) is used.
    }

    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};

int main()
{
    Rectangle f{};
    f.print();

    Rectangle x{2.0, 3.0};
    x.print();

    Rectangle y{4.0};
    y.print();

    return 0;
}