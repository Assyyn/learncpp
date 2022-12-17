#include <iostream>
#include <iterator> // for std::size

bool isVowel(char ch)
{
    switch (ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
        default:
            return false;
    }
}

int main()
{
    char name[]{"Maddie"};
    int arrayLength{static_cast<int>(std::size(name))};
    int numVowels{0};

    // 'ptr' is a pointer to a char, so every iteration we get a single
    // character from 'name'
    // ptr != (name + arrayLength) ; name decays to a pointer
    // so (name+arrayLength) just points to the null-terminator of name[]
    // where we stop iterating
    for (char* ptr{name}; ptr != (name + arrayLength); ++ptr)
    {
        if (isVowel(*ptr))
        {
            ++numVowels;
        }
    }

    std::cout << name << " has " << numVowels << " vowels.\n";

    return 0;
}