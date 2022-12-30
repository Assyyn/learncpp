// friend functions can access the private data of the class that declare them
// as being a 'friend'. They don't have a *this pointer because they are not
// members of the class

#include <iostream>

class Accumulator
{
private:
    int m_value{0};

public:
    void add(int value)
    {
        m_value += value;
    }

    // Make the reset() function a friend of the class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // and can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

int main()
{
    Accumulator acc;
    acc.add(10); // add 10 to the accumulator
    reset(acc);  // reset the accumulator to 0

    return 0;
}