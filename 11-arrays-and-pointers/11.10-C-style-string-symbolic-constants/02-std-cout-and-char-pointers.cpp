#include <iostream>

int main()
{
    const char* name{"Yuukiee"};
    char greet[]{"Hi!"};

    std::cout << name << '\n';  // prints "Yuukiee"
    std::cout << greet << '\n'; // prints "Hi!"

    // As you can see, std::cout makes assumptions about our intent whenever it
    // is passed an object of type [(const) char*] and prints out the underlying
    // string instead of the pointer's value

    // a problem with this:
    // consider we want to (for whatever reason) print out the memory address of
    // an object of type char
    char ch{'A'};
    std::cout << "address of ch: " << &ch
              << '\n'; // we want the address printed, but &ch has type
                       // char*, so it tries to print this as a string!
    // in mine, the above statement printed "AHi!"

    std::cout << static_cast<void*>(&ch)
              << '\n'; // If such a case really does arise, we can simply cast
                       // the address to (void*) to stop std::cout from treating
                       // it as char*

    return 0;
}