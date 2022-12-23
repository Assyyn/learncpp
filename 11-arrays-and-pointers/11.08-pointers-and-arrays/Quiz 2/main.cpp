/* Write a function named findValue that takes a pointer to the beginning and a
 * pointer to the end (1 element past the last) of an array, as well as a value.
 * The function should search for the given value and return a pointer to the
 * first element with that value, or the end pointer if no element was found.
 * */

#include <iostream>
#include <iterator>

// did it with templates, for fun
template <typename T>
T* findValue(T* begin, T* end, T value)
{
    for (T* ptr{begin}; ptr != end; ++ptr)
    {
        if (*ptr == value)
            return ptr;
    }

    return end;
}

int main()
{
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};

    // Search for the first element with value 20.
    int* found{findValue(std::begin(arr), std::end(arr), 20)};

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
        // print The index of the found element in arr:
        std::cout << found - std::begin(arr) << '\n';
    }

    return 0;
}