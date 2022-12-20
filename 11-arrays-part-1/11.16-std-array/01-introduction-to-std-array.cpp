#include <array>

int main()
{
    // declaration and initialization:
    std::array<int, 3> myArray; // declare an integer array with length 3

    std::array<int, 4> myArray2{9, 7, 5, 3};    // list(uniform initialization)
    std::array<int, 4> myArray3 = {9, 7, 5, 4}; // initializer list

    // with std::array you cannot omit the array length when providing an
    // initializer:
    // std::array<int, > myArray4{9, 7, 5, 3, 1};
    // std::array<int> myArray5{9, 7, 5, 3, 1};
    // illegal, array length must be known at compile-time

    // since C++17, it is allowed to omit type and size(both but not one at a
    // time)
    std::array array{9, 7, 5, 3, 1}; // the type is deduced to std::array<int,5>
    std::array array2{9.3, 2.1}; // the type is deduced to std::array<double,2>

    // since C++20, we can also do this:
    auto array3{
        std::to_array<int, 5>({9, 7, 5, 3, 1})}; // specify type and size
    auto array4{
        std::to_array<int>({9, 7, 5, 3, 1})}; // specify type only, deduce size
    auto array5{std::to_array({9, 7, 5, 3, 1})}; // deduce type and size

    // But std::to_array is more expensive than creating a std::array directly,
    // because it actually copies all the elements from a C-style array to a
    // std::array. Therefore, std::to_array should be avoided when the array is
    // created many times(e.g. in a loop)

    return 0;
}