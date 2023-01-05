#include "Fraction.h"

int main()
{
    Fraction f1{5, 3};
    Fraction f2{7, 2};
    Fraction f3{9, 5};

    f1 = f2 = f3; // chained assignment

    f1 = f1; // self-assignment

    return 0;
}