#include <iostream>

int diff(int x, int y)
{
    return (x - y);
}

int main()
{
    auto x{4};       // '4' is an int, so x gets type int
    auto y{4l};      // '4l' is a long, so y gets type long
    auto sum{x + y}; // x is implicitly converted to long, resulting in sum being of type long(therefore might be difficult to deduce type by simply looking at it)
    auto difference {diff(x,y)};    // diff() returns int, so difference is initialized as an int

    const int c{1};
    auto c2 {c};    // drops 'const'
    const auto c3 {c};  // needs to be explicitly stated

    return 0; 
}