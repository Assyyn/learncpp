#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray
{
private:
    int* m_array{};
    int m_length{};

public:
    IntArray(int length)
    {
        assert(length > 0);

        m_length = length;
        m_array = new int[static_cast<std::size_t>(m_length)]{};
    }

    // destructor
    ~IntArray()
    {
        // Dynamically delete the array we allocated ath the end of object
        // lifetime
        delete[] m_array;
    }

    void setValue(int index, int value)
    {
        m_array[index] = value;
    }

    int getValue(int index)
    {
        assert(index > 0 && index < m_length);
        return m_array[index];
    }

    int getLength()
    {
        return m_length;
    }
};

int main()
{
    IntArray arr(10);

    for (int i{0}; i < arr.getLength(); ++i)
    {
        arr.setValue(i, i + 1);
    }

    std::cout << "The value of element 5 is: " << arr.getValue(5) << '\n';

    return 0;
}