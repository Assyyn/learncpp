#include <cstring>
#include <iostream>
#include <string>
#include <string_view>

// first convert the  std::string_view to a std::string,
// then the std::string to a c-string using its member function c_str()

int main()
{
    std::string_view sv{"Michael"};

    sv.remove_suffix(4); // make it 'Mic'

    std::string s{sv};

    // Get the null-terminated C-style string
    auto szNullTerminated{s.c_str()};

    // Pass the null-terminated string to a function that we want to use:
    std::cout << s << " has " << std::strlen(szNullTerminated)
              << " letter(s)\n";

    return 0;
}

// As it can be useful sometimes, we can use it if no other method exists to do
// something with our string that only C-strings can provide.

// However, creating a std::string every time we want to pass a std::string_view
// as a C-style string is expensive, so this should be avoided if possible