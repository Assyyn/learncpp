#include <algorithm>
#include <array>
#include <iostream>

bool isOdd(int x)
{
    return (x % 2);
}

int main()
{
    std::array array{10, 2, 34, 70};

    // Sometimes we want to see if there is a value in a container that matches
    // some condition (e.g. a string that contains a specific substring) rather
    // than an exact value. In such cases, std::find_if is perfect.
    auto found{std::find_if(array.begin(), array.end(), isOdd)};

    if (found == array.end())
    {
        std::cout << "Did not find any odd numbers\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}