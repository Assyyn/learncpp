#include <string>
#include <iostream>

using namespace std::literals;

int main()
{
    constexpr std::string name{"Alex"s}; // compiler error

    std::cout << "My name is " << name << '\n';

    return 0;
} // if you need constexpr strings, use std::string_view instead