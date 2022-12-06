#include <iostream>

auto sum(int x, int y) // fine: can be used like this
{
    return (x + y);
}

auto findX(int x); // cannot be used before it is fully defined, as there is not enough information for the compiler to deduce it's return type

auto someFcn(bool b)
{
    if (b)
        return 1.3;
    else
        // compiler error
        return "hi!"; // must always return same type, makes sense
}

int main()
{
    int x{0};
    findX(x);
}

auto findX(int x)
{
    return 9;
}

// favor explicit return types over function return type deduction for normal functions