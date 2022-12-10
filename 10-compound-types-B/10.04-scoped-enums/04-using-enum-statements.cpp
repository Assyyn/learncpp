#include <iostream>
#include <string_view>

// this is only available after C++20

enum class Color
{
    black,
    blue,
    white,
};

constexpr std::string_view getColor(Color color)
{
    // using enum allows us to bring the enumerators of the scoped enumeration
    // to current scope
    using enum Color; // C++20
    switch (color)
    {
        case black:
            return "black";
        case blue:
            return "blue";
        case white:
            return "white";
        default:
            return "???";
    }
}

int main()
{
    Color ink{Color::black};

    std::cout << "The ink is: " << getColor(ink) << '\n';

    return 0;
}