#include <algorithm>
#include <array>
#include <iostream>

// std::array doesn't decay to a pointer when passed to a function
void printLength(const std::array<double, 4>& myArray)
{
    // the size() function returns the length of the std::array
    std::cout << "length of myArray: " << myArray.size() << '\n'; // prints 4
}

// range-based for loops work with std::array:
void printArray(const std::array<double, 4>& myArray)
{
    for (auto number : myArray)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array myArray{9.0, 4.5, 2.25, 1.0};

    printLength(myArray);

    printArray(myArray);

    // std::sort can be used to sort a std::array
    std::sort(myArray.begin(), myArray.end());

    std::cout << "sorted array:\n";
    printArray(myArray);

    return 0;
}