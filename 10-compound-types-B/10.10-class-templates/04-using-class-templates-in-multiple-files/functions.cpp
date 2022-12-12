#include "pair.h"

#include <iostream>

void foo()
{
    Pair<int, int> x{1, 2};
    std::cout << '[' << x.first << ',' << x.second << ']';
}