#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    std::array<std::string_view, 4> fruits{"Apple", "Banana", "Hazelnut",
                                           "Mango"};

    // let the user pick the substring to search for:
    std::cout << "What do you want to search for?: ";
    std::string search;
    std::cin >> search;

    // capture search(by const value by default) to use in our lambda.
    // capture by value creates a const copy of the variable captured, and
    // captured values may not necessarily have the same type as the original
    // variable
    auto lookup{[search](std::string_view str) {
        // search = "Something else"; // error: search is const by default
        return str.find(search) != std::string_view::npos;
    }};

    auto found{std::find_if(fruits.begin(), fruits.end(), lookup)};

    if (found == fruits.end())
    {
        std::cout << "couldn't find " << search << '\n';
    }
    else
        std::cout << "Found " << search << " in: " << *found << '\n';

    return 0;
}
