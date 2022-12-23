#include <iostream>
#include <vector>

// In the context of the std::vector, length is how many elements are being used
// in the array, whereas capacity is how many elements were allocated in memory

// Exploring vector length and capacity behavior

template <typename T>
void printLC(const std::vector<T>& array)
{
    std::cout << "length: " << array.size() << " capacity: " << array.capacity()
              << '\n';
}

int main()
{
    // no elements are allocated when a vector is default-initialized,
    // so it's length = capacity = 0.
    std::vector<int> array{};

    // observe the difference in array size and length
    array = {1, 2, 3, 4, 5}; // array length = 5, capacity = 5
    printLC(array);

    // notice that the capacity does not change this time,
    // this is because resizing an array is computationally expensive
    array = {5, 6, 7}; // array length = 3
    printLC(array);

    array = {1};    // array length = 1
    printLC(array); // capacity is still 5; the std::vector object will not
                    // resize itself unless it has to grow

    return 0;
}