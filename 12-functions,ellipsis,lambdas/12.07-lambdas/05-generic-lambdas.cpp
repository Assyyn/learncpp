#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Because lambdas with one or more auto parameter can potentially work with a
// wide variety of types, they are called generic lambdas.

int main()
{
    constexpr std::array<std::string_view, 12> months{
        "January", "February",  "May",     "June",     "July",
        "August",  "September", "October", "November", "December"};

    // search for two consecutive months that start with the same letter:
    const auto sameLetter{std::adjacent_find(
        months.begin(), months.end(),
        [](const auto& a, const auto& b) { return a[0] == b[0]; })};

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                  << " start with the same letter(" << sameLetter->at(0)
                  << ")\n";
    }

    return 0;
}