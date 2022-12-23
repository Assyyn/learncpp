#include <iostream>

// in order to iterate through the array, for-each needs to know how big the
// array is, which means knowing the array size. Because arrays that have
// decayed to a pointer don't know their size, for-each loops will not work with
// them!

int sumArray(const int array[]) // array is a pointer
{
    int sum{0};

    for (auto number : array) // compile error, the size of array isn't known
    {
        sum += number;
    }

    return sum;
}

int main()
{
    constexpr int array[]{9, 7, 5, 3, 1};

    std::cout << sumArray(array) << '\n'; // array decays into pointer here

    return 0;
}

// similarly, dynamic arrays won't work with for-each loops for the same reason.