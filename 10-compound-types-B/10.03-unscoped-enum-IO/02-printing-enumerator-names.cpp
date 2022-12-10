#include <iostream>
#include <string>
#include <string_view> // C++17

enum Color
{
    black,
    red,
    white,
};

// the typical way to do this is to test our enumeration against every possible
// enumerator, using a switch-statement (or if statements, but they are not
// preferable)
std::string getColorS(Color color)
{
    switch (color)
    {
        case black:
            return "black";
        case red:
            return "red";
        case white:
            return "white";
        default:
            return "???";
    }
}

// an even better method would be to return std::string_view as they allow to
// return string literals in a way that is much less expensive to copy than
// std::string. for example:
constexpr std::string_view getColorSV(Color color)
{
    switch (color)
    {
        case black:
            return "black";
        case red:
            return "red";
        case white:
            return "white";
        default:
            return "???";
    }
}

int main()
{
    Color shirt{red};

    std::cout << "Your shirt is " << getColorS(shirt) << '\n';

    std::cout << "Your shirt is " << getColorSV(shirt) << '\n';

    return 0;
}
