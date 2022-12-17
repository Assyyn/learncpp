#include <iostream>

void changeArray(int* ptr)
{
    *ptr = 5;
}

int main()
{
    int array[]{0, 0, 3, 4, 2};
    std::cout << "Element 0 has value: " << array[0] << '\n'; // 0

    // the array will decay to a pointer, pointing to the actual array
    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n'; // 5

    return 0;
}