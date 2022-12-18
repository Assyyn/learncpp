#include <iostream>

int main()
{
    void* ptr{nullptr}; // void pointers can be set to null pointer

    // void pointers can point to dynamically allocated memory, but deleting
    // them can result in undefined behavior.
    void* ptr2{new int[2]}; // this also makes no sense, really
    delete ptr2;            // avoid
    ptr2 = nullptr;

    // there is no such thing as a void reference, because what does it refer
    // to?(philosophical topic, interesting)
    // void& x{ptr}; // illegal

    // As pointed(ha!) out before, it can be used in some places. Like this:
    char ch{'A'};
    std::cout << &ch << '\n'; // this will print 'A' as it has type char*
    std::cout << (static_cast<void*>(&ch)) << '\n';
    // explicitly printing memory location

    return 0;
}