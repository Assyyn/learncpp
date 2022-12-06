#include <iostream>
#include <string>

// note: i used namespaces to showcase these examples and avoid ambiguity 
namespace a
{
    void print(int)
    {
    }

    void print(double)
    {
    }
}

namespace c
{
    void print(const char)
    {
    }
}

namespace d
{
    void print(double) {}
    void print(std::string) {}
}

class X
{
public:
    operator int() { return 0; }    // a user-defined conversion from X to int
};

int main()
{
    // steps to resolve overloaded function calls

    // step 1.1: search for exact match. if found, resolved.
    // exact match: the type of arguments in the function call exactly matches the type of parameters of overloaded function
    a::print(0);   // exact match: a::print(int)
    a::print(2.3); // exact match: a::print(double)

    // step 1.2: tries to apply trivial conversions to arguments in the function call. if an (exact) match is found, resolved.
    // trivial conversions are a set of specific conversion rules that will modify types(without modifying the value) for purposes of finding a match.
    // for example: a non-const can be trivially converted to a const type
    char x;
    c::print(x); // x trivially converted to const char. match found: c::print(const char)

    // step 2: tries to apply numeric promotion to argument(s) in the function call. if (after promotion) match found, resolved
    a::print('a');  // promoted to int, now matches print(int)
    a::print(true); // promoted to int, now matches print(int)
    a::print(2.3f); // promoted to double, now matches print(double)

    // step 3: tries to apply numeric conversion to arguments
    d::print('a'); // no direct match i.e d::print(char) or promotion match i.e d::print(int). so numeric conversion applied

    // step 4: tries to find a match through any user defined conversions
    X y;
    a::print(y);    // converts x to int. found match

    // step 5: still not found? looks for a matching function that uses ellipsis (ellipsis are covered in 12.6)

    // step 6: if no matches have been found by this point, the compiler will give up and produce an error
    std::string z;
    a::print(z); // no matches can be made, unresolved error
}