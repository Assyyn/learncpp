#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{"Banana", "Hazelnut", "Apple",
                                                  "Walnut"};

    // use a lambda inside our std::find_if
    auto found{std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
        return str.find("nut") != std::string_view::npos;
    })};

    // improving readability by storing the Lambda in a variable, then passing
    // it
    auto isNut{[](std::string_view str) {
        return str.find("nut") != std::string_view::npos;
    }};

    // the code is easier to follow now -> find if there is nut in the
    // collection!
    found = std::find_if(arr.begin(), arr.end(), isNut);

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
        std::cout << "Found: " << *found << '\n';

    return 0;
}