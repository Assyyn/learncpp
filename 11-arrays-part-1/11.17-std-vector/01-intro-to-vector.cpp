#include <vector>

int main()
{
    // no need to specify length at the declaration
    std::vector<int> array;

    // use initializer list to initialize array (before C++11)
    std::vector<int> array2 = {9, 7, 5, 3, 1};

    // use uniform initialization to initialize array
    std::vector<int> array3{9, 7, 5, 3, 1};

    // as with std::array, the type can be omitted since C++17
    std::vector array4{9, 7, 5, 3, 1}; // deduced to std::vector<int>

    array[6] = 2;    // no bounds checking
    array.at(7) = 3; // does bounds checkings

    // As of C++11, you can also assign values to a std::vector using an
    // initializer list
    array = {0, 1, 2, 3, 4}; // okay, array length is now 5
    array = {9, 8, 7};       // okay, array length is now 3
}