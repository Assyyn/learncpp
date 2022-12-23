#include <array>

int main()
{
    // You can assign values to std::array using an initializer list:
    std::array<int, 5> myArray;
    myArray = {1, 3, 5, 7, 9};
    myArray = {1, 2}; // elements 2,3,4 are set to zero
    // myArray = {0, 1, 2, 3, 4, 5}; // too many elements in the initializer
    // list

    // using subscripts is the same:
    myArray[0] = 1; // set element 0 to 1
    // there is no bounds checking when using subscripts, like built-in fixed
    // arrays:
    myArray[5] = 10; // no error is produced by compiler

    return 0;
}