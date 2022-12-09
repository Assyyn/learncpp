// Unscoped enumerations are named such because they put their enumerator names
// into the same scope as the enumeration definition itself
// (as opposed to creating a new scope region like a namespace does).

// for example:

enum Color // defined in the global namespace
{          // all Color enumerators are now also in the global namespace

    red,
    // red can be accessed as 'red' without having to scope to Color::red
    green, // however, something like Color::green is also fine(but mostly not used with unscoped enums)
    blue,
};

enum Feeling
{
    // blue is already in the global namespace
    blue, // error: naming collision with the blue from Color
    happy,
    sad,
};

int main()
{
    Color apple{red};          // my apple is red
    Color grass{Color::green}; // the grass is green
    Feeling me{blue};

    return 0;
}