#include <iostream>

int main()
{
    int array[]{9, 7, 5, 3, 1};

    // we can see from the output of the code below that:
    // 1. Arrays are laid out sequentially in memory
    // 2. Indexes might just be an implementation of pointer arithmetic
    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';

    std::cout << "addresses using pointer arithmetic: \n";

    std::cout << "Element 0 is at address: " << array << '\n';
    std::cout << "Element 1 is at address: " << array + 1 << '\n';
    std::cout << "Element 2 is at address: " << array + 2 << '\n';

    // we can similarly access array elements using pointer arithmetic
    std::cout << "array[0]: " << array[0] << '\n';
    std::cout << "array[0]: " << *array << '\n';

    std::cout << "array[1]: " << array[1] << '\n';
    // it is written like this so that the pointer dereferencing is done 'after'
    // pointer arithmetic ->  *(array+1)
    std::cout << "array[1]: " << *(array + 1) << '\n';
    // so it turns out array[n] is really just *(array+n)

    return 0;
}