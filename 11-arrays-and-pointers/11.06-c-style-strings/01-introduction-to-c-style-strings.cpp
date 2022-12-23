#include <iostream>

int main()
{
    // initialisation
    char myString[]{"string"}; // array of size 7
    // [s][t][r][i][n][g][\0]. \0 is a null terminator that indicates the end of
    // the string

    // test if it really has 7 characters
    constexpr int length{static_cast<int>(std::size(myString))};

    std::cout << myString << " has " << length << " characters\n";

    // print all characters in myString
    for (int index{0}; index < length; ++index)
    {
        std::cout << static_cast<int>(myString[index]) << ' ';
    }

    std::cout << '\n';

    // change individual characters in a c-style string:
    myString[1] = 'o';

    std::cout << myString << '\n'; // prints 'soring'

    return 0;
}