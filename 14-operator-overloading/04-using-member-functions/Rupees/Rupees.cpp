#include "Rupees.h"

Rupees Rupees::operator+(const Rupees& other)
{
    return {this->m_rupees + other.m_rupees};
}

std::ostream& operator<<(std::ostream& os, const Rupees& rupees)
{
    os << "Rs." << rupees.value();
    return os;
}

std::istream& operator>>(std::istream& is, Rupees& rupees)
{
    is.ignore(3, ' ');
    is >> rupees.m_rupees;
    return is;
}