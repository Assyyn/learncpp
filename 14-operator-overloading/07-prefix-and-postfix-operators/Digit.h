#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

class Digit
{
private:
    int m_digit{};

public:
    // skipped validity checks
    Digit(int digit = 0) : m_digit{digit} {}

    // ++Digit i.e. prefix
    Digit& operator++();
    Digit& operator--();

    // Digit++ i.e. postfix
    Digit operator++(int);
    Digit operator--(int);

    friend std::ostream& operator<<(std::ostream& os, const Digit& d);
};

std::ostream& operator<<(std::ostream& os, const Digit& d)
{
    os << d.m_digit;
    return os;
}

Digit& Digit::operator++()
{
    if (m_digit == 9)
        m_digit = 0;
    else
        ++m_digit;
    return *this;
}

Digit& Digit::operator--()
{
    if (m_digit == 0)
        m_digit = 9;
    else
        --m_digit;
    return *this;
}

Digit Digit::operator++(int)
{
    Digit temp{m_digit};

    ++*this;

    return temp;
}

Digit Digit::operator--(int)
{
    Digit temp{m_digit};

    --*this;

    return temp;
}

#endif