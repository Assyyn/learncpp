#include <iostream>

// dynamic memory allocation is a way for running programs to request memory
// from the operating system when needed. This memory is allocated from a much
// larger pool of memory managed by the OS called the heap memory.
// On modern machines, the heap can be gigabytes in size.

int main()
{
    // using new to allocate memory for data of specific type
    new int;  // dynamically allocate an integer (and discard the result)
    new char; // dynamically allocate a char (and discard the result)

    // a pointer to the allocated memory is returned by 'new', which we can now
    // assign to our pointer variable so we can access the allocated memory
    // later
    int* ptr{new int}; // dynamically allocate an integer and assign its address
                       // to ptr so we can access it later
    // we can now perform indirection through the pointer to access the memory:
    *ptr = 7;

    // initializing a dynamically allocated variable:
    int* ptr1{new int(9)};  // use direct initialization
    int* ptr2{new int{10}}; // use uniform initialization

    // after we are done with a dynamically allocated variable, we need to
    // explicitly tell C++ to free the memory for reuse
    delete ptr;                // ptr is now a dangling pointer
    std::cout << *ptr << '\n'; // this will cause undefined behavior
    ptr = nullptr;             // to avoid trying to access the freed memory
                               // (avoid undefined behavior like above)

    // Best Practice: set deleted pointers to nullptr unless they are going out
    // of scope immediately forward and save yourself the headache
    delete ptr1;
    ptr1 = nullptr;

    delete ptr2;
    ptr2 = nullptr;

    return 0;
}