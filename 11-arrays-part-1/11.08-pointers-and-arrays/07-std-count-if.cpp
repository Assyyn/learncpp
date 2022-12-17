#include <algorithm>
#include <iostream>
#include <iterator>

// Because counting elements is common, the algorithms library offers
// std::count_if, which counts elements that fulfill a condition. We can replace
// the for-loop with a call to std::count_if.

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
    char name[]{"Yuuki"};

    // walk through all the elements of name and count how many calls to isVowel
    // return true
    auto numVowels{std::count_if(std::begin(name), std::end(name), isVowel)};

    std::cout << name << " has " << numVowels << " vowels.\n";

    // if the array has decayed to a pointer, we can calculate begin and end
    // manually
    if (numVowels == std::count_if(name,
                                   name + (static_cast<int>(std::size(name))),
                                   isVowel))
        std::cout << "This method is also valid!\n";

    return 0;
}