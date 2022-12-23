#include <array>
#include <iostream>

int main()
{
    std::array myArray{7, 3, 1, 9, 5};

    // Iterate through the array and print the value of the elements
    for (decltype(myArray.size()) i{0}; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}