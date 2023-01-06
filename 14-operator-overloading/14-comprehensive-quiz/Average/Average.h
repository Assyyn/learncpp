#ifndef AVERAGE_H
#define AVERAGE_H

#include <cstdint> // for std::int_fast32_t, std::int_fast8_t
#include <iostream>

class Average
{
private:
    std::int_fast32_t m_total{0};
    std::int_fast8_t m_numbers{0};

public:
    Average() {}
    Average(const Average& copy) :
        m_total{copy.m_total}, m_numbers{copy.m_numbers}
    {}

    Average& operator+=(int value);

    friend std::ostream& operator<<(std::ostream& os, const Average& avg);
};

Average& Average::operator+=(int value)
{
    m_total += value;
    ++m_numbers;
    return *this; // so it's chainable
}

std::ostream& operator<<(std::ostream& os, const Average& avg)
{
    os << static_cast<double>(avg.m_total) / avg.m_numbers;
    return os;
}

#endif