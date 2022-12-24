// classic case of infinite recursion -> stack overflow

#include <iostream>

// infinitely recursive function
void foo()
{
    foo();
    std::cout << "hi";
    // keeps calling itself, adding stack frames until finally the stack
    // overflows and the program is terminated
}

int main()
{
    foo();

    return 0;
}