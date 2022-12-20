/* Question #4

Write a function to print a C-style string character by character. Use a pointer
to step through each character of the string and print that character. Stop when
you hit the null terminator. Write a main function that tests the function with
the string literal “Hello, world!”.
*/

#include <iostream>
#include <iterator>

void print(const char* str)
{
    for (auto ptr{str}; *ptr != '\0'; ++ptr)
    {
        std::cout << *ptr;
    }

    std::cout << '\n';
}

int main()
{
    print("Hello, world!");

    return 0;
}