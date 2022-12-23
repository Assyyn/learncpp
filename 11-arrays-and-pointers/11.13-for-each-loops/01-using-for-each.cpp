#include <iostream>

int main()
{
    constexpr int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (int number : fibonacci) // iterate over array fibonacci
    {
        std::cout << number << '\n'; // we access the array element for this
                                     // iteration through variable number
    }
    std::cout << '\n';

    // Using auto to deduce the type of array elements for us(to avoid
    // mistakenly doing (unneeded)type conversion):
    for (auto number : fibonacci)
    {
        std::cout << number << '\n';
    }
    std::cout << '\n';

    return 0;
}