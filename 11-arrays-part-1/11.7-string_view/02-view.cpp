#include <iostream>
#include <string_view>

// a string_view can be thought of as a read-only reference to a string,
// with added functionalities that a 'const std::string&' cannot provide

int main()
{
    char arr[]{"Hare"};
    std::string_view str{arr};

    std::cout << str << '\n';

    // Change 'a' to 'f' in arr
    arr[1] = 'f';

    // the changes to arr are reflected in str
    // as str is a 'view' into arr
    std::cout << str << '\n';

    return 0;
}