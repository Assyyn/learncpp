/* Declare a fixed array with the following names: Alex, Betty, Caroline, Dave,
 * Emily, Fred, Greg, and Holly. Ask the user to enter a name. Use a for each
 * loop to see if the name the user entered is in the array.
 */

#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view names[]{"Alex",  "Betty", "Caroline", "Dave",
                                       "Emily", "Fred",  "Greg",     "Holly"};

    std::cout << "Enter a name: ";
    std::string username{};
    std::cin >> username;

    bool found{false};
    for (std::string_view name : names)
    {
        if (username == name)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        std::cout << username << " was found.\n";
    }
    else
    {
        std::cout << username << " was not found.\n";
    }

    return 0;
}