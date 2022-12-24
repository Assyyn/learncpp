#include <functional> // for std::function
#include <iostream>

// an alternative way to declare and store function pointers  is std::function

int goo()
{
    return 10;
}

bool complement(bool x)
{
    return !x;
}

int main()
{
    // syntax: std::function<return-type(arguments)> function-pointer-name
    std::function<bool(bool)> fcnPtr{&complement};

    // only implicit dereferencing is allowed
    std::cout << fcnPtr(false) << '\n';

    (*fcnPtr)(false); // error

    // aliasing std::function:
    using fncAlias = std::function<bool(bool)>;
    fncAlias fPtr{&complement};

    // as of C++17, we can let CTAD figure out the template parameters of a
    // std::function from an initializer:
    std::function iPtr{&goo};

    // CTAD doesn't work on aliases though:
    using IntGet = std::function goo; // error

    return 0;
}