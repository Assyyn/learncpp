// Constructors are allowed to call non-constructor member functions (and
// non-member functions), so a better solution is to use a normal
// (non-constructor) member function to handle the common setup tasks, like
// this:
#include <iostream>

class Foo
{
private:
    const int m_value{};

    void setup() // setup is private so it can only be accessed by our
                 // constructors
    {
        // code to do some common setup tasks(e.g. open a file or a database)
        std::cout << "Setting things up...\n";
    }

public:
    Foo()
    {
        setup();
    }

    Foo(int value) : m_value{value}
    {
        setup();
    }
};

int main()
{
    Foo a;
    Foo b{5};

    return 0;
}