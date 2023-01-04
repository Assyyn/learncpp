#include "MyString.h"

#include <iostream>

int main()
{
    MyString name{"Hannah"};

    std::cout << name(2, 3) << ' ' << name.substr(2, 3);

    return 0;
}