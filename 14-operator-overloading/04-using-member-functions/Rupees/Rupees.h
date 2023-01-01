#ifndef RUPEES_H
#define RUPEES_H

#include <iostream>

class Rupees
{
private:
    int m_rupees{};

public:
    Rupees(int rupees = 0) : m_rupees{rupees} {}

    int value() const { return m_rupees; }

    Rupees operator+(const Rupees& other);
    Rupees operator+(int value) const { return {this->m_rupees + value}; }
    Rupees operator-(int value) const { return {this->m_rupees - value}; }
    Rupees operator-(const Rupees& other) const
    {
        return {this->m_rupees - other.m_rupees};
    }
    void operator+=(const Rupees& rupees) { *this = *this + rupees; }

    friend Rupees operator-(int value, const Rupees& rupees)
    {
        return {-(rupees.operator-(value).value())};
    }

    friend std::istream& operator>>(std::istream& is, Rupees& rupees);
};

std::ostream& operator<<(std::ostream& os, const Rupees& rupees);
std::istream& operator>>(std::istream& is, Rupees& rupees);

#endif // RUPEES_H