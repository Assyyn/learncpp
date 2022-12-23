#include <iostream>

// taking advantage of static duration of a string literal
const char* getName()
{
    return "Yuukie";
}

int main()
{
    // create C-style string symbolic constant using pointers:
    const char* myName{"Yuukie"}; // pointer to symbolic constant
    std::cout << myName << '\n';

    // the compiler places the string "Yuukie\0"  into read
    // only memory somewhere, and then sets the pointer to point to it.

    // For optimization purposes, multiple string literals may be consolidated
    // into a single value. For Example:
    const char* name{"Harry"};
    const char* name2{"Harry"};
    // The compiler may opt to combine these into a single shared single string
    // literal, with both name and name2 pointed at the same address

    // String literals have static duration rather than automatic duration
    std::cout << "getName(): " << getName()
              << '\n'; // this works because of the static duration property

    return 0;
}