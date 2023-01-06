#include "IntArray.h"

#include <cassert>

IntArray::IntArray(int length) : m_length{length}
{
    assert(length >= 0 && "cannot construct array of negative size");

    if (length)
        m_data = new int[length];
    else
        m_data = nullptr;
}

IntArray::IntArray(const IntArray& v2)
{
    reallocate(v2.m_length);
    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = v2.m_data[index];
    }
}

IntArray& IntArray::operator=(const IntArray& v)
{
    if (this == &v)
        return *this;

    reallocate(v.m_length);

    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = v.m_data[index];
    }

    return *this;
}

int& IntArray::operator[](int index)
{
    assert(index >= 0 && "cannot access negative index(es)");
    assert(index < m_length && "subscript out of range");

    return m_data[index];
}

void IntArray::erase()
{
    delete[] m_data;
    m_length = 0;
    m_data = nullptr;
}

// reallocate memory for new values; erases old data. fast
void IntArray::reallocate(int newLength)
{
    erase();
    m_length = newLength;
    m_data = new int[newLength];
}

// resize the array, trying to keep existing elements(as long as new length
// is greater than old one). slow
void IntArray::resize(int newLength)
{
    if (m_length == newLength) // do Nothing
        return;

    if (m_length <= 0)
    {
        erase();
        return;
    }

    // length is at least 1 element(implicit)
    int* data = new int[newLength];

    int elementsToCopy{(newLength > m_length) ? m_length : newLength};

    for (int index{0}; index < elementsToCopy; ++index)
    {
        data[index] = m_data[index];
    }

    // free previously used memory first
    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    assert(index >= 0 && index <= m_length);

    // make a copy of the old array, by parts
    int* data = new int[m_length + 1];

    // copy upto index
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }

    data[index] = value;

    // copy after index
    for (int after{index}; after < m_length; ++after)
    {
        data[after + 1] = m_data[after];
    }

    // free used memory and assign ownership of new array's memory to m_data
    delete[] m_data;
    m_data = data;
    // m_length had not been incremented before
    ++m_length;
}

void IntArray::remove(int index)
{
    assert(index >= 0 && index < m_length);

    // if its the last element,
    if (m_length == 1) // don't need to check for index==0
    { // if its the last and has passed the assertion, then index has to be 0
        erase();
        return;
    }

    int* data = new int[m_length - 1];

    // copy upto deleted element
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }

    // copy from `[index]`
    for (int after{index + 1}; after < m_length; ++after)
    {
        data[after - 1] = m_data[after];
    }

    delete[] m_data;
    m_data = data;
    --m_length;
}