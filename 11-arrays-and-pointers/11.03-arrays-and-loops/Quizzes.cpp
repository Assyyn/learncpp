#include <iostream>
#include <limits>

int main()
{
    constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};

    int number{};
    while (number < 1 or number > 9) // get a valid number input
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        }
    }

    for (int i = 0; i < static_cast<int>(std::size(array));
         ++i) // print the array
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // find and print number in the array
    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)
    {
        if (array[i] == number)
        {
            std::cout << "The number " << number << " has index " << i << '\n';
            break;
        }
    }

    // // prior to C++17
    // int size = sizeof(array) / sizeof(array[0]); // size of array
    // for (int i = 0; i < size; ++i)
    // {
    //     std::cout << array[i] << ' ';
    // }

    return 0;
}