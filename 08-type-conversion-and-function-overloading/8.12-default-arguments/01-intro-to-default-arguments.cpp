#include <iostream>

int someFcn(int x, int y = 8)
{
    return x - y;
}

void fcnX(int x = 8, int y) // illegal; default arguments can only be supplied for rightmost parameters
{
}

void print(int x, int y = 10);

void print(int x, double y = 20.5)
{
}

int main()
{
    int x{10};
    someFcn(x, 9); // fine, y becomes 9
    someFcn(x);    // fine, y = 8
    print(x);   // ambiguous function call
}

/*
void print(int x, int y = 10)   // error: redefinition of default argument
{
}
*/

// do this instead
void print(int x, int y) // y will still have a default 10
{
}