// in 11.16.04, we observed that we have to specify the element type and array
// length when using std::array as a function parameter. how can we solve this?
// the answer is using templates

#include <array>
#include <cstddef>
#include <iostream>
#include <string>

// printArray is a template function
template <typename T, std::size_t size>
void printArray(const std::array<T, size>& myArray)
{
    // we use const auto& here, because we do not know if the type is going to
    // be cheap or expensive to copy, and also because we do not plan on
    // manipulating the array
    for (const auto& element : myArray)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array myArray{9.0, 5.3, 6.2, 1.0};
    printArray(myArray);

    std::array names{"Harry", "Sou"};
    printArray(names);

    return 0;
}