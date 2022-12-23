#include <iostream>
#include <string_view>

int main()
{
    // string_view also provides similar functionalities like std::string
    std::string_view str{"Trains are fast!"};

    std::cout << str.length() << '\n'; // 16
    std::cout << str.substr(0, str.find(' '))
              << '\n'; // characters until whitespace.prints 'Trains'

    std::cout << (str == "Trains are fast!") << '\n'; // 1

    // Since C++20
    std::cout << str.starts_with("Boats") << '\n'; // 0
    std::cout << str.ends_with("fast!") << '\n';   // 1

    std::cout << str << '\n'; // Trains are fast!

    return 0;
}
