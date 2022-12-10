#include <iostream>

// defining scoped enums:
enum class Color
{
    blue,
    white,
    black,
};

enum class Feeling
{
    blue, // no need of separate namespace to avoid naming collisions
    happy,
    sad,
};

int main()
{
    // the enumerators are put inside enumeration scope, and hence not directly
    // accessible
    Color color = Color::blue;
    Feeling feeling = Feeling::blue;

    // no implicit conversion(to int) is allowed by the compiler
    if (color == feeling)
    {
        std::cout << "color and feeling are equal\n";
    }

    // you can still static_cast scoped enumerators to ints(and vice versa):
    int x{static_cast<int>(
        Color::blue)}; // x initialized with integral value of blue

    std::cout << "x = " << x << '\n';

    Color myBox{static_cast<Color>(2)}; // myBox is black
    if (myBox == Color::black)
        std::cout << "myBox is black\n";

    Color ink{0}; // you can also directly initialize them with integral values
    if (ink == Color::blue)
        std::cout << "ink is blue\n";

    return 0;
}

// Note: scoped enums (enum class) are not considered a class type
// Best practice:
// Favor 'enum class' over 'enum' unless there's a compelling reason to do so
// otherwise

/* Despite the benefits that scoped enumerations offer, unscoped enumerations
 * are still commonly used in C++ because there are situations where we desire
 * the implicit conversion to int (doing lots of static_casting get annoying)
 * and we don’t need the extra namespacing.
 * */