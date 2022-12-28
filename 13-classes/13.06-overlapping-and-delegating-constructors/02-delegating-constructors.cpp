// Constructors are allowed to call other constructors from the same class. This
// process is called delegating constructors (or constructor chaining).

// If you have multiple constructors that have the same functionality, use
// delegating constructors to avoid duplicate code.

#include <iostream>

// the following code shows how we could use constructor chaining to reduce
// redundancy
class Something
{
public:
    Something()
    {
        // we wanted to do this everytime in Something(int) & Something(int,int)
        std::cout << "inside default constructor..\n";
    }

    // let Something() do its thing
    Something(int x) : Something{}
    {
        // std::cout << "inside default constructor..\n"; -> reduced this
        // redundant action
        std::cout << "inside Something(" << x << ")\n";
    }

    // let Something(x) do its thing
    Something(int x, int y) : Something{x}
    {
        // std::cout << "inside default constructor..\n";
        // std::cout << "inside Something(" << x << ")\n";
        /* reduced above duplicate code*/

        std::cout << "inside Something(" << x << ',' << y << ")\n";
    }
};

int main()
{
    Something(3);

    Something(5, 6);

    return 0;
}