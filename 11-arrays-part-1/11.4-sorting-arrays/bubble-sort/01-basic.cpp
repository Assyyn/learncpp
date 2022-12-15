#include <iostream>

int main()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    constexpr int length{static_cast<int>(std::size(array))};

    for (int iterations{0}; iterations < length - 1; ++iterations)
    {
        for (int currentIndex{0}; currentIndex < (length - 1);
             ++currentIndex) // go through the array
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
            }
        }
    }

    // print sorted array
    for (int currentIndex{0}; currentIndex < length; ++currentIndex)
    {
        std::cout << array[currentIndex] << ' ';
    }
    std::cout << '\n';

    return 0;
}