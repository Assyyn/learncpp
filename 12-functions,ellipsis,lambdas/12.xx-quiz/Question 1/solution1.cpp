#include <iostream>

// Write a function named max() that takes two doubles and returns the larger of
// the two
double max(const double x, const double y)
{
    return (x > y) ? x : y;
}

// A function named swap() that swaps two integers
void swap(int& x, int& y)
{
    int temp{x};
    x = y;
    y = temp;
}

// A function named getLargestElement() that takes a dynamically allocated array
// of integers and returns the largest number in such a way that the caller can
// change the value of the element returned (don’t forget the length parameter).
int& getLargestElement(int* array, const int length)
{
    int largestElementIndex{0};
    for (int i{0}; i < length; ++i)
    {
        if (array[largestElementIndex] < array[i])
        {
            largestElementIndex = i;
        }
    }

    return array[largestElementIndex];
}

int main()
{
    // testing function(s)
    // a
    std::cout << max(1.3, 9.5) << '\n';

    // b
    int x{2};
    int y{3};
    swap(x, y);
    std::cout << x << y << '\n';

    // c
    int length{10};
    int* array{new int[length]};
    // populate array with numbers in range (1-10)
    for (int i{0}; i < length; ++i)
    {
        array[i] = i + 1;
    }

    std::cout << getLargestElement(array, length) << '\n';
    delete[] array;
    array = nullptr;

    return 0;
}