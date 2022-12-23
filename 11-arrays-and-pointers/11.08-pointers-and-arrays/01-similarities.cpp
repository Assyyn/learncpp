#include <iostream>

int main()
{
    // a fixed array will decay to a pointer that points to the first element in
    // the array when used in an expression
    int array[]{2, 3, 4, 5, 6, 7};

    // print address of array[0]:
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to:
    std::cout << "The array decays to a pointer holding address: " << array
              << '\n';

    // This allows us to treat fixed arrays and pointers identically in most
    // cases:
    int array1[5]{1, 244, 9, 0};

    // dereferencing an array returns the first element
    std::cout << "array1[0]: " << *array1 << '\n';
    // we are not actually dereferencing the array, but the pointer that it
    // decays to

    // We can also assign a pointer to point at the array:
    int array2[]{22, 31, 4};
    std::cout << *array2 << '\n';

    int* ptr{array2};
    std::cout << *ptr << '\n';

    return 0;
}