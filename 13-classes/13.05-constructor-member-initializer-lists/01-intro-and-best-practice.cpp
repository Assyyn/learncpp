#include <iostream>

// Use member initializer lists to initialize your class member variables
// instead of assignment
class Something
{
private:
    int m_value1{};
    double m_value2{};
    char m_value3{};

public:
    Something(int value1, double value2, char value3 = 'c') :
        m_value1{value1}, m_value2{value2}, m_value3{value3}
    // directly initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", "
                  << m_value3 << ")\n";
    }
};

int main()
{
    // value1 = 1, value2=2.2, value3 gets default value 'c'
    Something something{1, 2.2};
    something.print();
    return 0;
}