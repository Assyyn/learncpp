#include <iostream>
#include <string_view>

int main()
{
    std::string_view str{"Trains are fast!"};

    std::cout << str.length() << '\n'; // 16
    std::cout << str.substr(0, str.find(' '))
              << '\n'; // characters until whitespace.prints 'Trains'

    return 0;
}