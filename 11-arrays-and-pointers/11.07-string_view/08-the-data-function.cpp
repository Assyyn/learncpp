#include <cstring>
#include <iostream>
#include <string_view>

int main()
{
    std::string_view str{"balloon"};

    std::cout << str << '\n';

    // We use std::strlen because it's simple, this could be any other function
    // that needs a null-terminated string.
    // It's okay to use data() because we haven't modified the view, and the
    // string is null-terminated.
    std::cout << std::strlen(str.data()) << '\n'; // 7

    // changing our view of the string can have unintended effects with the
    // data() function:
    std::string_view sv{"Mannequin"};

    // remove the "M"
    sv.remove_prefix(1);

    // remove the "quin"
    sv.remove_suffix(4);

    // the data() function returns a pointer to the first character in the
    // substring being viewed, which is the c-style string
    // "annequin", as when we remove 'quin' from view the resulting 'anne'
    // is not actually null-terminated
    std::cout << sv << " has " << std::strlen(str.data()) << " letters\n";
    std::cout << "sv is " << sv << '\n';
    std::cout << "str.data() is " << sv.data() << '\n';

    return 0;
}