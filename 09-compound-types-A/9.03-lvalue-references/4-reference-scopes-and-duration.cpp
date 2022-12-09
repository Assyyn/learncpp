#include <iostream>

// references follow the same scoping and duration rules that normal variables do:
int main()
{
    int x{4};
    int &refX{x};

    // do something ...

    return 0;
}   // both x and refX die here