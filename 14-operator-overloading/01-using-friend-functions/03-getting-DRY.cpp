#include <iostream>

// MinMax objects keep track of the minimum and maximum values(only) that have
// been given to them, using operator+
class MinMax
{
private:
    int m_min{};
    int m_max{};

public:
    MinMax(int min, int max) : m_min{min}, m_max{max} {}

    int getMin() const
    {
        return m_min;
    }

    int getMax() const
    {
        return m_max;
    }

    friend MinMax operator+(const MinMax& m1, const MinMax& m2);
    friend MinMax operator+(const MinMax& m, int value);
    friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
    int min{m1.m_min < m2.m_min ? m1.m_min : m2.m_min};

    int max{m1.m_max > m2.m_max ? m1.m_max : m2.m_max};

    // implicitly converts it into a constructor for MinMax
    return {min, max};
}

MinMax operator+(const MinMax& m, int value)
{
    int min{m.m_min < value ? m.m_min : value};

    int max{m.m_max > value ? m.m_max : value};

    return {min, max};
}

// as overloads involving an integer perform the same task regardless of
// ordering, we can define one and use it in the other.
// we follow the DRY rule by doing so
MinMax operator+(int value, const MinMax& m)
{
    // call operator+(MinMax,int)
    return m + value;
}

int main()
{
    // test
    MinMax m1{0, 0};
    MinMax m2{10, 15};
    MinMax m3{-1, 25};

    MinMax mFinal{m1 + m2 + -2 + m3 + 19};

    std::cout << "Result: (" << mFinal.getMin() << ", " << mFinal.getMax()
              << ")\n";

    return 0;
}