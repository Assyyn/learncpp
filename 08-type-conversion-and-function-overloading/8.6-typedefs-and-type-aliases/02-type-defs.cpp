// typedefs are an older way of creating type aliases

#include <iostream>

int main()
{
    // both of these are same
    typedef double Miles;
    using Miles = double;

    // typedefs can get confusing
    typedef int (*Fcntype)(double, char);  // Fcntype hard to find
    using Fcntype = int (*)(double, char); // Fcntype easy to find

    return 0;
}

// prefer type aliases over typedefs