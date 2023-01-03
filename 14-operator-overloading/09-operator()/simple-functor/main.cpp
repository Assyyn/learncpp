#include "Accumulator.h"

#include <iostream>
int main()
{
    Accumulator acc{};
    // using our accumulator looks just like a normal function call
    std::cout << acc(10) << '\n'; // prints 10
    std::cout << acc(20) << '\n'; // prints 30

    return 0;
}

// With functors, we can instantiate as many separate functor objects as we need
// and use them all simultaneously.

//  Although simple functors (such as the example above) are fairly easily
//  understood, functors are typically used in more advanced programming topics