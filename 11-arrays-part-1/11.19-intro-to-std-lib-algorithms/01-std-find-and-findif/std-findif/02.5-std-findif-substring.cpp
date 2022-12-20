#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return (str.find("nut") != std::string_view::npos);
}

int main()
{
    std::array<std::string_view, 4> names{"Joe", "Wallnut", "Nutella", "Hedge"};

    // Scan our array to see if any elements contain the substring "nut"
    auto found{std::find_if(names.begin(), names.end(), containsNut)};

    if (found == std::end(names))
    {
        std::cout << "Couldn't find nut\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}