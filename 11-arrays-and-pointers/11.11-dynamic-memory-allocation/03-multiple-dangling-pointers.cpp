#include <iostream>

int main()
{
    int* ptr{new int{}}; // dynamically allocate an integer
    int* otherPtr{ptr};  // otherPtr is now pointed at that same memory location

    delete ptr;    // ptr and otherPtr are now dangling pointers
    ptr = nullptr; // ptr is now a nullptr

    // however, otherPtr is still a dangling pointer!

    return 0;
}

/* There are a few best practices that can help here.

First, try to avoid having multiple pointers point at the same piece of dynamic
memory. If this is not possible, be clear about which pointer “owns” the memory
(and is responsible for deleting it) and which pointers are just accessing it.

Second, when you delete a pointer, if that pointer is not going out of scope
immediately afterward, set the pointer to nullptr.

*/