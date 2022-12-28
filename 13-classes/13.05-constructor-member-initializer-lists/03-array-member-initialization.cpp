#include <iostream>

class Something
{
private:
    const int m_array[5];

public:
    // since C+11
    Something() : m_array{1, 2, 3, 4, 5}
    // use uniform initialization to initialize our member array
    {}
};