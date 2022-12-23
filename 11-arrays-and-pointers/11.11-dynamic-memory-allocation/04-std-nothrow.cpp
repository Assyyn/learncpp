#include <iostream>

int main()
{
    // consider we ask for memory from the OS, but it cannot give us that memory
    // this will cause new to fail and throw a bad_alloc exception, which will
    // simply terminate the program with an error if not properly handled.

    // std::nothrow can be used to tell new to return a null pointer if memory
    // can't be allocated like this
    int* value{new (std::nothrow) int}; // value will be set to a nullptr if the
                                        // integer allocation fails

    // The best practice is to check all memory requests actually succeeded
    // before using the allocated memory
    if (!value) // handle cases where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }

    return 0;
}