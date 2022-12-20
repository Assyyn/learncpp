#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool contains_le(std::string_view str)
{
    return (str.find("le") != std::string_view::npos);
}

int main()
{
    std::array<std::string_view, 4> words{"apple", "less", "let", "maple"};

    // occurences of substring 'le' using std::count_if
    auto occurences{std::count_if(words.begin(), words.end(), contains_le)};

    std::cout << "le occurs " << occurences << " times\n";

    return 0;
}