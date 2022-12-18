#include <iostream>

int main()
{
    int value{5};
    void* ptr{&value};

    // std::cout << *ptr << '\n'; // illegal: dereference of void pointer

    int* intPtr{static_cast<int*>(
        ptr)}; // however, if we cast our void pointer to an int pointer..

    std::cout << *intPtr << '\n'; // then we can dereference a result

    return 0;
}