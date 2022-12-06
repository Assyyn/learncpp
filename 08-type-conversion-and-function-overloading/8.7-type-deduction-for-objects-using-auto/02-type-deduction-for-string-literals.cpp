#include <iostream>
#include <string_view>
#include <string>

int main()
{
    auto s {"Hello, world!"};   // type will be const char*, not std::string

    using namespace std::literals;
    auto s1 {"Hello, world!"s}; // type is std::string
    auto s2 {"Hello, world!"sv};    // type is std::string_view

    return 0; 
}

// note: type-deduction only works on variables that are initialized
