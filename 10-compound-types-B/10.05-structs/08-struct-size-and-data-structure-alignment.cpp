#include <iostream>

// the size of a struct is 'at least' as large as the size of all its members
// combined
struct Foo // 2+4+8 = 14
// should be 14bytes, but is 16bytes
{
    short a{};
    int b{};
    double c{};
};

struct Foo1 // 2+2+4+8 = 16
{
    short a{};
    short aa{};
    int b{};
    double c{};
};

struct Foo2 // 2+4+8+2 = 16, but its size is 24?
{
    short a{};
    int b{};
    double c{};
    short aa{}; // note that this is the only change in Foo1 & Foo2
};

int main()
{
    std::cout << "The size of Foo is " << sizeof(Foo) << '\n';   //  16
    std::cout << "The size of Foo1 is " << sizeof(Foo1) << '\n'; //  16
    std::cout << "The size of Foo2 is " << sizeof(Foo2) << '\n'; //  24

    return 0;
}

// This phenomenon of adding gaps into structures is known as padding