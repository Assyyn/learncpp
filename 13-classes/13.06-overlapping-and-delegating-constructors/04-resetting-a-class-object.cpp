// We may want our class object to return to having its default values, where we
// could try this(for now):
#include <iostream>

class Something
{
private:
    int m_a{0};
    int m_b{1};

public:
    Something() = default;

    Something(int a, int b) : m_a{a}, m_b{b} {}

    void print()
    {
        std::cout << m_a << ", " << m_b << '\n';
    }

    //  if the class is assignable (meaning it has an accessible assignment
    //  operator), we can create a new class object, and then use assignment to
    //  overwrite the values in the object we want to reset:
    void reset()
    {
        // create new default class object and assign it to current object
        *this = Something{};
    }
};

int main()
{
    Something x{1, 2};
    x.print();

    x.reset(); //--> reset to default values (0,1)
    x.print(); // produces expected result

    return 0;
}