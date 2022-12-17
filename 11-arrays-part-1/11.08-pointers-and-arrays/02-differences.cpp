#include <iostream>

int main()
{
    // Unlike a fixed array, the pointer to array doesn't know it's size
    int array[4]{2, 3, 5}; // prints array length*sizeof(int) = 16
    std::cout << "size of array is: " << sizeof(array) << '\n';

    int* ptr{array}; // the size of a pointer is fixed
    std::cout << "size of ptr is: " << sizeof(ptr)
              << '\n'; // the size of a pointer

    // using address-of operator(&) on pointers vs fixed arrays:
    int array1[2]{4, 0};
    std::cout << array1 << '\n';  // type int[2], prints x
    std::cout << &array1 << '\n'; // type int(*)[2]. prints x

    std::cout << '\n';

    int* ptr1{array1};
    std::cout << ptr1 << '\n';  // type int*, prints y
    std::cout << &ptr1 << '\n'; // type int**, prints y-8

    return 0;
}