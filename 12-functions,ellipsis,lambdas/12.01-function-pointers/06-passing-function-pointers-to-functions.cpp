#include <iostream>
#include <utility> // for std::swap

// Let's make a custom comparision function to pass to SelectionSort():
bool ascending(int x, int y)
{
    return (x > y); // swap if first element greater than second
}

// sort in descending order
bool descending(int x, int y)
{
    return x < y; // swap if second element is greater than first
}

// 'weird' comparisions for sorting
bool oddFirst(int x, int y)
{
    // if x is odd and y is even(no swap needed)
    if (x % 2 && !(y % 2))
        return false;

    // if x is even and y is odd(swap needed)
    if (y % 2 && !(x % 2))
        return true;

    // else sort in ascending order
    return ascending(x, y);
}

// sorting algorithm from a few lessons back, but with support for custom
// comparision functions!
// you can also provide a standard functions for the caller to use for their
// convenience

// you can also set a default comparision function parameter, here making the
// ascending() function the default is quite convenient as it is very common to
// want to sort an array in ascending order.
void SelectionSort(int* array, int size,
                   bool (*comparisonFcn)(int, int) = ascending)
{
    // Step through each element in the array
    for (int startIndex{0}; startIndex < (size - 1); ++startIndex)
    {
        // bestIndex is the index of the *user-defined* best element we have
        // encountered so far
        int bestIndex{startIndex};

        // Look for the best element remaining in the array (starting at
        // startIndex+1)
        for (int currentIndex{startIndex + 1}; currentIndex < size;
             ++currentIndex)
        {
            // If the current element is smaller than our previously found
            // smallest
            if (comparisonFcn(array[bestIndex], array[currentIndex]))
            {
                // This is the best number for this iteration
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with the smallest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// print array
void printArray(int* arr, int size)
{
    for (int index{0}; index < size; ++index)
    {
        std::cout << arr[index] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int arr[]{1, 3, 10, 24, 4};

    // sort array using ascending() function:
    SelectionSort(arr, 5, ascending);
    printArray(arr, 5);

    // sort array using descending() function:
    SelectionSort(arr, 5, descending);
    printArray(arr, 5);

    // sort array using oddFirst() function:
    SelectionSort(arr, 5, oddFirst);
    printArray(arr, 5);

    SelectionSort(arr, 5); // sorts in ascending order by default. perfect!
    printArray(arr, 5);

    return 0;
}