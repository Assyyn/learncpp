// The Standard library is full of classes made for our benefit, std::vector,
// std::string, and std::array etc are all classes
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector a{1, 9, 20, 44};    // instantiate a vector class object
    std::string b{"Hello, World!"}; // string class object

    // member functions
    std::cout << a.back() << b.c_str() << '\n';

    return 0;
}