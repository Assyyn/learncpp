#include <iostream>

int main()
{
    char myString[]{"string"}; // c-style string of length 7

    char* ptr{myString};
    ptr[6] = 's'; // oops; the null character was replaced by 'p' by accident

    std::cout << myString
              << '\n'; // std::cout now keeps printing everything in adjacent
                       // memory until it happens to hit a 0

    return 0;
}