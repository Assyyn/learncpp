#include <iostream>

// Consider the following code:
int main()
{
    int x{};
    int &ref1{x}; // lvalue reference to x
    int &ref2{ref1}; // == int &ref2{x} as ref1 IS just another alias for x

    return 0;
}

// Because ref2 (a reference) is initialized with ref1 (a reference), you might be tempted to conclude that ref2 is a reference to a reference.
// It is not. Because ref1 is a reference to var, when used in an expression (such as an initializer), ref1 evaluates to var.
// So ref2 is just a normal lvalue reference (as indicated by its type int&), bound to var.

// references to references are not supported by C++ 
// references are also not objects as they are not required to exist or occupy storage