// While the following syntax is 'technically valid', don't use this in real
// code.

#include <iostream>

int main()
{
    int array[]{2, 3, 4, 5, 9};

    // this works!
    std::cout << 2 [array] << '\n'; // 4
    // array[2] is same as: *(array+2)
    // *(array+2) is same as: *(2+array)
    // *(2+array) is same as: 2[array] !!!

    return 0;
}