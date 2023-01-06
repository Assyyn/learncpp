#include "IntArray.h"

IntArray::IntArray(int length) : m_length{length}
{
    assert(m_length >= 0 && "Bad array length supplied!");

    if (!m_length)
        m_arr = nullptr;
    else
        m_arr = new int[m_length];
}

// no need to check for invalid length
// because other must be a valid IntArray
IntArray::IntArray(const IntArray& other) :
    m_length{other.m_length}, m_arr{m_length ? new int[m_length] : nullptr}
{
    for (int i{0}; i < m_length; ++i)
    {
        m_arr[i] = other.m_arr[i];
    }
}

IntArray& IntArray::operator=(IntArray other)
{
    swap(*this, other);
    return *this;
}

int& IntArray::operator[](int index)
{
    assert(index >= 0 && "Expected index >= 0");
    assert(index < m_length && "index out-of-range");

    return m_arr[index];
}

void swap(IntArray& a1, IntArray& a2)
{
    using std::swap;

    swap(a1.m_arr, a2.m_arr);
    swap(a1.m_length, a2.m_length);
}

std::ostream& operator<<(std::ostream& os, const IntArray& a1)
{
    if (!a1.m_arr)
        return os;

    for (int i{0}; i < a1.m_length; ++i)
    {
        os << a1.m_arr[i] << ' ';
    }

    return os;
}