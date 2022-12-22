#include <iostream>

// foo() is a function that starts at memory address, say 'x'
int foo()
{
    return 3;
}

int main()
{
    // when a function is called, execution jumps to the address of the
    // function, in this case 'x'
    foo();

    // we meant to call foo(), but we're printing foo itself!
    std::cout << foo << '\n';

    // the compiler can decide what to convert the function pointer to for
    // printing, let's try converting it to void* before printing
    std::cout << reinterpret_cast<void*>(foo) << '\n';
    // prints memory address!

    return 0;
}