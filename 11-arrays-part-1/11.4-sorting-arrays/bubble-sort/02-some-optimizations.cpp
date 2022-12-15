#include <iostream>

int main()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    constexpr int length{static_cast<int>(std::size(array))};

    for (int iteration{0}; iteration < length - 1; ++iteration)
    {
        // keep track of swapping
        bool swapped{false};

        // the last 'length - iteration' elements have already been sorted,
        // exclude them from future sorts
        int endOfArrayIndex{length - iteration};

        // go through the array
        for (int currentIndex{0}; currentIndex < (endOfArrayIndex - 1);
             ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        // if no swaps occured, then array must be sorted already
        if (!swapped)
        {
            std::cout << "Early termination on iteration " << iteration + 1
                      << '\n';
            break;
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