#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<int>& x)
{
    for (int i : x)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector array{2, 4, 8, 16, 32, 64};
    std::cout << "Before search and replace:\n";
    print(array);

    std::cout << "Enter a value to search and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // std::find returns an iterator to the first instance of the found
    // element(or the end of the container, if not found)
    auto found{std::find(std::begin(array), std::end(array), search)};

    // if we found the element:
    if (found != std::end(array))
    {
        *found = replace; // replace
        std::cout << "After search and replace:\n";
    }
    else
    {
        std::cout << "Could not find " << search << '\n';
    }
    print(array);

    return 0;
}