#include "MyString.h"

#include <iostream>

int main()
{
    // initialization
    MyString name{"Yuuki", 6};
    std::cout << name << '\n';

    // copy
    MyString name2{name};
    std::cout << name2 << '\n';

    // assign
    MyString name3{"Jamie", 6};
    name = name3;
    std::cout << name << '\n';

    return 0;
}