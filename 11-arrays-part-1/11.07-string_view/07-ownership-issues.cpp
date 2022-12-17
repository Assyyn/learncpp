#include <iostream>
#include <string>
#include <string_view>

std::string_view askForName()
{
    std::cout << "What's your name?\n";

    // Use a std::string, because std::cin needs to modify it.
    std::string name{};
    std::cin >> name;

    // We're switching to std::string_view for demonstration purposes only.
    // If you already have a std::string, there's no reason to switch to a
    // std::string_view
    std::string_view view{name};

    std::cout << "Hello " << view << '\n';

    return view;
} // name dies, so does the string that name created.

int main()
{
    std::string_view view{askForName()};

    // view is observing a string that already died.
    std::cout << "Your name is " << view << '\n'; // undefined behavior

    /*The same can happen when we create a std::string_view from a std::string
     * and then modify the std::string. Modifying a std::string can cause its
     * internal string to die and be replaced with a new one in a different
     * place. The std::string_view will still look at where the old string was,
     * but it’s not there anymore.*/
    std::string str{"Moon River"};
    std::string_view vStr{str};

    // modify str:
    str.assign("Have a good day!");
    std::cout << vStr << '\n'; // undefined behavior

    return 0;
}