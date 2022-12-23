#include <iostream>
#include <vector>

void printCapacity(const std::vector<int>& array)
{
    std::cout << "Capacity: " << array.capacity() << '\n';
}

int main()
{
    // length = capacity = 20
    std::vector<int> array(20);

    // length = 10, capacity = 20
    array.resize(10);
    printCapacity(array);

    // the subscript operator 'can' access the value because it is not
    // range-checked
    std::cout << "Using array[10]: " << array[10] << '\n';

    // even though the capacity of the array is 20, we cannot access elements
    // beyond current length with the at() function:
    std::cout << "Using array.at(10): " << array.at(10); // error

    return 0;
}