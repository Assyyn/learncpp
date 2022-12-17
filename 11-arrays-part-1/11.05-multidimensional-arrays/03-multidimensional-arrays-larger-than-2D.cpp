#include <iostream>

int main()
{
    // arrays above 2D are easier to initialize by first initializing them to 0,
    // then explicitly assigning values using nested loops
    int array1[4][3][2]{}; // visualising this array like we did 2D arrays is
                           // not as intuitive

    // accessing elements is the same as 2D arrays:
    std::cout << array1[1][2][0];

    return 0;
}