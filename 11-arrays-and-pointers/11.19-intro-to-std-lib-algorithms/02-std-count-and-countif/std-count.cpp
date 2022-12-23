#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array numbers{1, 0, 1, 22, 1, 0, 1};

    // find total occurences in numbers of 1, using std::count
    auto occurences{std::count(numbers.begin(), numbers.end(), 1)};

    std::cout << "1 occurs " << occurences << " times\n";

    return 0;
}