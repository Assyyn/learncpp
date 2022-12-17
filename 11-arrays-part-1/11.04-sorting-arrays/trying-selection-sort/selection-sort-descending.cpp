// descending selection sort from my code

#include <iostream>

int main()
{
    int array[]{2, 3, 4, 10, 0, -21, -2};

    constexpr int size{static_cast<int>(std::size(array))};

    int startIndex{0};
    while (startIndex < size)
    {
        int largestIndex{startIndex};

        for (int i{startIndex}; i < size; ++i) // start from startIndex
        {
            if (array[largestIndex] < array[i])
            {
                // if a smaller element has been found
                largestIndex = i;
            }
        }

        std::swap(array[startIndex], array[largestIndex]);
        startIndex++;
    }
    // sort(array, std::size(array));

    for (int i{0}; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
}