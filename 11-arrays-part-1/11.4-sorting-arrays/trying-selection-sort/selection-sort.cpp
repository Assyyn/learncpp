// my code for the algorithm!

#include <iostream>

int main()
{
    int array[]{2, 3, 4, 10, 0, -21, -2};

    constexpr int size{static_cast<int>(std::size(array))};

    int startIndex{0};
    while (startIndex < size)
    {
        int smallestIndex{startIndex};

        for (int i{startIndex}; i < size; ++i) // start from startIndex
        {
            if (array[smallestIndex] > array[i])
            {
                // if a smaller element has been found
                smallestIndex = i;
            }
        }

        std::swap(array[startIndex], array[smallestIndex]);
        startIndex++;
    }
    // sort(array, std::size(array));

    for (int i{0}; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
}