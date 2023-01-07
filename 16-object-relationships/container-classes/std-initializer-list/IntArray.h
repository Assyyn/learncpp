// let's add a std::initializer-list functionality to our IntArray class

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <cassert>
#include <initializer_list> // for std::initializer list

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    IntArray(std::initializer_list<int>
                 list); // to allow us to initialize with a initializer list
    IntArray(const IntArray& v2);
    IntArray& operator=(const IntArray& v);
    IntArray& operator=(std::initializer_list<int> list);

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