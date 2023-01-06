#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <cassert>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& v2);
    IntArray& operator=(const IntArray& v);

    ~IntArray() { delete[] m_data; }
    int getLength() { return m_length; }

    int& operator[](int index);

    void erase();

    void reallocate(int newLength);

    void resize(int newLength);

    void insertBefore(int value, int index);
    void remove(int index);

    void insertAtTop(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
};

#endif