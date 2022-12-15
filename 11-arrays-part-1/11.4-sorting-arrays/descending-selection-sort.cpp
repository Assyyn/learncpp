#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get
    // there)
    for (int startIndex{0}; startIndex < length - 1; ++startIndex)
    {
        // largestIndex is the index of the largest element we’ve encountered
        // this iteration Start by assuming the largest element is the first
        // element of this iteration
        int largestIndex{startIndex};

        // Then look for a larger element in the rest of the array
        for (int currentIndex{startIndex + 1}; currentIndex < length;
             ++currentIndex)
        {
            // If we've found an element that is larger than our previously
            // found largest
            if (array[currentIndex] > array[largestIndex])
                // then keep track of it
                largestIndex = currentIndex;
        }

        // largestIndex is now the largest element in the remaining array
        // swap our start element with our largest element (this sorts it into
        // the correct place)
        std::swap(array[startIndex], array[largestIndex]);
    }

    // Now that the whole array is sorted, print our sorted array as proof it
    // works
    for (int index{0}; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}