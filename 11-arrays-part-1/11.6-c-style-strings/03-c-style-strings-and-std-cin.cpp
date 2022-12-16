#include <iostream>

int main()
{
    char name[255]{}; // declare array large enough to hold 254 characters +
                      // null terminator

    std::cout << "Enter your name: ";
    std::cin >> name; // this doesn't have any way of stopping the user from
                      // entering more than 254 characters, and hence is poor
                      // programming practice
    std::cout << "You entered: " << name << '\n';

    char address[255]{}; // declare array large enough to hold 254 characters +
                         // null terminator

    std::cout << "Enter your address: ";
    std::cin.getline(address, static_cast<int>(std::size(address)));
    // cin.getline() will read upto 254 characters into
    // address(leaving room for the null terminator).
    // Any excess characters will be discarded. In this way, we guarantee that
    // the array will not overflow

    std::cout << "You entered: " << name << '\n';

    return 0;
}