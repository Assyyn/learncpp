// If the program tries to put too much information on the stack, stack overflow
// will result. Stack overflow happens when all the memory in the stack has been
// allocated -- in that case, further allocations begin overflowing into other
// sections of memory.
#include <iostream>

int main()
{
    int stack[10000000]; // try to allocate array

    // the following statement does not execute
    std::cout << "hi " << stack[0]; // we use stack[0] here so the compiler
                                    // doesn't optimize the array away

    return 0;
}

// This program tries to allocate a huge (likely 40MB) array on the stack.
// Because the stack is not large enough to handle this array, the array
// allocation overflows into portions of memory the program is not allowed to
// use.