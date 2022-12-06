#include <iostream>

// the same name can be used to represent the same fundamental thing, (here: adding numbers)
// so long as each has different parameter types or they can be otherwise differentiated
// more on this in 8.10
int add(int x, int y)
{
    return (x + y);
}

int add(int a, int b) // is essentially the same as the preceding one,
// nothing is 'actually different' except variable names
{
    return a + b;
}

double add(double x, double y)
{
    return (x + y);
}

int add(int x, int y, int z)
{
    return (x + y + z);
}

int main()
{
    // the following piece of code demonstrates basic overload resolution(compiler matches functions according to parameters given):
    add(2, 3);      // add(int,int)
    add(2.1, 3.1);  // add(double,double)
    add(9, 10, 11); // add (int,int,int)
    // add(2, 3.6);   // no function add(int,double), error
    add(2, 3);
    return 0;
}