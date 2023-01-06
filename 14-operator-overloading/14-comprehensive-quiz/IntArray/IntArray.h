#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <iostream>

class IntArray
{
private:
    int m_length{0};
    int* m_arr{nullptr};

public:
    IntArray(int length = 0);
    IntArray(const IntArray& other);

    ~IntArray() { delete[] m_arr; }

    IntArray& operator=(IntArray other);
    int& operator[](int index);

    friend void swap(IntArray& a1, IntArray& a2);
    friend std::ostream& operator<<(std::ostream& os, const IntArray& a1);
};

#endif