// Because operator[] is limited to a single parameter, it is not sufficient to
// let us index a two-dimensional array.

// However, because the () operator can take as many parameters as we want it to
// have, we can declare a version of operator() that takes two integer index
// parameters, and use it to access our two-dimensional array. Here is an
// example of this:
#include <cassert>

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // for const objects
};

double& Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}