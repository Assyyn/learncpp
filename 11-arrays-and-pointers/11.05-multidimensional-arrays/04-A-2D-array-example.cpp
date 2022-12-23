#include <iostream>

// Calculate a multiplication table

int main()
{
    constexpr int numRows{10};
    constexpr int numCols{10};

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate the table
    // We don't need to calculate row and col 0 since they are always 0,
    // but we can write to them instead
    for (int row{0}; row < numRows; ++row)
    {
        for (int column{0}; column < numCols; ++column)
        {
            product[row][column] = (row + 1) * (column + 1);
        }
    }

    // Print the table
    for (int row{0}; row < numRows; ++row)
    {
        for (int col{0}; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}

// Two dimensional arrays are commonly used in tile-based games, where each
// array element represents one tile. They’re also used in 3d computer graphics
// (as matrices) in order to rotate, scale, and reflect shapes.