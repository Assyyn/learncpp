#include <cstring>
#include <iostream>

int main()
{
    // strcpy
    char source[]{"Copy this!"};
    char dest[50];
    std::strcpy(dest, source);
    std::cout << dest << '\n'; // prints "Copy this!"

    // can overflow arrays:
    char source1[]{"Copied!"};
    char dest1[2]; // note that the length of dest is only 5 chars!
    std::strcpy(dest1, source1); // causes overflow!
    std::cout << dest1 << '\n';

    // strlen()

    // only use 5 characters (4 letters + null terminator)
    char name[30]{"Alex"};

    std::cout << "Name: " << name << '\n';
    std::cout << name << " has " << std::strlen(name) << " letters.\n"; // 5
    std::cout << name << " has " << std::size(name)
              << " characters in the array.\n"; // 30

    return 0;
}

/*
Other useful functions:
strcat() -- Appends one string to another (dangerous)
strncat() -- Appends one string to another (with buffer length check)
strcmp() -- Compare two strings (returns 0 if equal)
strncmp() -- Compare two strings up to a specific number of characters
(returns 0 if equal)
*/

// Whenever they are not absolutely necessary,
// Use std::string or std::string_view instead of C-style strings