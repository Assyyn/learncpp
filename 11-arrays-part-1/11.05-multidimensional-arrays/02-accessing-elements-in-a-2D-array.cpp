#include <iostream>

int main()
{
    // initialize a 2d array to 0:
    int array[2][3]{};

    constexpr int noRows{2};
    constexpr int noCols{3};

    // print the array elements
    for (int row{0}; row < noRows; ++row) // access the rows of our array
    {
        for (int column{0}; column < noCols;
             ++column) // access the array in current row
        {
            std::cout << "[" << row << "][" << column
                      << "]:" << array[row][column] << '\t';
        }
        std::cout << '\n'; // print a new line for new row
    }
}