#include <iostream>

int main()
{
    int array[2][3]; // a 1-element array of 2-element arrays
    /* the above 2-dimensional array can be represented as:
    [0][0] [0][1] [0][2] // row 0
    [1][0] [1][1] [1][2] // row 1

    here, [2][3] are the number of rows and columns
    respectively.
    */

    // accesssing array elements:
    array[0][0] = 1; // set first element of first 2-element array as 1

    // initialization:
    int array1[2][3]{{1, 2, 3}, {4, 5, 6}};
    /* array1 representation:
    [0][0] [0][1] [0][2] // row 0 |||  1   2   3    // row 0
    [1][0] [1][1] [1][2] // row 1 |||  4   5   6    // row 1
    */

    // missing initializers are replaced with 0:
    int array2[2][3]{{2, 1}, {4, 2}};
    /* array2 representation:
    [0][0] [0][1] [0][2] // row 0 |||  2   1   0    // row 0
    [1][0] [1][1] [1][2] // row 1 |||  4   2   0    // row 1
    */
    // check if [0][2] is 0:
    std::cout << "array2[0][2]: " << array2[0][2] << '\n';

    // 2d array with initializer list can omit(only) the leftmost length
    // specification
    int array3[][3]{{1, 2, 3}, {4, 5, 6}};
    // automatic deduction to array3[2][3]

    // int array4[][]{{2, 2}, {4, 4}}; // not allowed

    // multidimensional arrays can still be initialized as 0:
    int array5[2][3]{};
    /* array5 initialized as
    [0][0] [0][1] [0][2] // row 0 |||  0   0   0    // row 0
    [1][0] [1][1] [1][2] // row 1 |||  0   0   0    // row 1
    */
}