#include <iostream>
#include <string>
#include <string_view>

void strLiterals()
{
    using namespace std::literals;
    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "moo\n"s;  // s suffix is a std::string literal
    std::cout << "boo\n"sv; // sv suffix is a std::string_view literal
}

int main()
{
    ::strLiterals(); // interesting way of asking the compiler to
                     // look for function definition in the global namespace
    return 0;
}