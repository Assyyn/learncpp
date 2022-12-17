#include <iostream>

int main()
{
    int value{1};
    int* ptr{&value};

    // When calculating the result of a pointer arithmetic expression, the
    // compiler always multiplies the integer operand by the size of the object
    // being pointed to. This is called scaling.
    std::cout << ptr << '\n';     // x
    std::cout << ptr + 1 << '\n'; // x + sizeof(int)
    std::cout << ptr + 2 << '\n'; // x + 2*sizeof(int)
    std::cout << ptr + 3 << '\n'; // ...

    std::cout << "---------------------------" << '\n';

    // so adding or reducing the value of our pointer makes it point to the next
    // or previous object of the same type
    short sValue{2};
    short* sPtr{&sValue};

    std::cout << sPtr << '\n';     // t
    std::cout << sPtr + 1 << '\n'; // t + sizeof(short)
    std::cout << sPtr + 2 << '\n'; // t + 2*sizeof(short)

    return 0;
}