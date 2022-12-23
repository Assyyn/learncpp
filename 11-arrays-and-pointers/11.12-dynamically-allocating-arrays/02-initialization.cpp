#include <iostream>

int main()
{
    int length;
    std::cin >> length;
    int* array{new int[length]{}};
    delete[] array;
    array = nullptr;

    // Prior to C++11, there was no easy way to initialize a dynamic array to a
    // non-zero value(i.e no initializer list support). So we had to loop
    // through the array and assign element values explicitly
    int* array1 = new int[5];
    array1[0] = 8;
    array1[1] = 0;
    array1[2] = 3;
    array1[3] = 5;
    array1[4] = 9;
    delete[] array1;
    array1 = nullptr;
    // Starting with C++11, initialization with initializer lists is possible
    int* dynamicArray{new int[5]{9, 7, 5, 3, 1}};
    delete[] dynamicArray;
    dynamicArray = nullptr;
    // we can use auto to prevent writing the type name twice:
    auto* array2{new int[5]{8, 19, 88, 88, 0}};
    delete[] array2;
    array2 = nullptr;

    return 0;
}