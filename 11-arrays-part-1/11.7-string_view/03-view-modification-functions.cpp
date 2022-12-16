// we can change what we view through std::string_view
// Below are some functions that let us do exactly that
// But once the view is changed, the only way to view the whole string again is
// to reset the view by reassigning the source string to it again.

#include <iostream>
#include <string_view>

int main()
{
    std::string a{"Peaches"};
    std::string_view str{a};

    std::cout << str << '\n';

    // Ignore the first character.
    str.remove_prefix(1);

    std::cout << str << '\n'; // eaches

    // Ignore the last 3 characters.
    str.remove_suffix(3);

    std::cout << str << '\n'; // eac

    // the underlying string has not changed, only our view of it
    std::cout << a << '\n'; // Peaches

    // reset the view: reassign
    str = a;

    // print str again to see the reset
    std::cout << str << '\n'; // Peaches

    return 0;
}