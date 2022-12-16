#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

void printCS(const std::string& cs)
{
    std::cout << cs << '\n';
}

int main()
{
    std::string s{"Hello, world!"};
    std::string_view sv{s};

    // We can pass any string argument to a function expecting a
    // std::string_view parameter
    printSV(s);               // ok:pass std::string
    printSV(sv);              // ok:pass std::string_view
    printSV("Hello, world!"); // ok:pass c-style string

    // but that's not the case for function expecting a const std::string&
    printCS(s); // ok: pass by std::string

    // printCS(sv); // error: cannot implicitly convert std::string_view to
    // const std::string

    printCS("Hello, world!"); // ok: pass c-style string

    return 0;
}

// we pass std::string_view by value becuase it is cheap to copy

// There is one case where making the parameter a const std::string& is
// generally better: if your function needs to call some other function that
// takes a C-style string or std::string parameter, then const std::string& may
// be a better choice, as std::string_view is not guaranteed to be
// null-terminated (something that C-style string functions expect) and does not
// efficiently convert back to a std::string.

/*Best practice

Prefer passing strings using std::string_view (by value) instead of const
std::string&, unless your function calls other functions that require C-style
strings or std::string parameters.

*/