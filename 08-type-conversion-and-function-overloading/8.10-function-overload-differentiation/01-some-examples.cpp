#include <iostream>

int add(int x, int y)
{
    return x + y;
}
// these two are easily distinct from each other : 'based on number of parameters'
int add(int x, int y, int z)
{
    return x + y + z;
}
// these two have different parameter types, clearly different: 'based on types of parameters'
double add(double x, double y, double z)
{
    return x + y + z;
}
// return types are NOT considered when differentiating overloaded functions. BAD
int add(double x, double y, double z)
{
    return x + y + z;
} // this is because it is not clear which one you want to call when you write: add(3.2,4.5,2.1).


// note: function names are mangled ("altered") during compilation based on various criteria like number and types of parameters etc
// it is done so that the linker has unique names to work with
// while in the source code two overloaded functions share a name, in compiled code, the names are actually unique
