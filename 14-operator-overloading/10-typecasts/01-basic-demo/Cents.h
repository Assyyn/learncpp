#pragma once

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents = 0) : m_cents{cents} {}

    // overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    friend std::ostream& operator<<(std::ostream& os, const Cents& cents);
};

std::ostream& operator<<(std::ostream& os, const Cents& cents)
{
    // cents will be implicitly cast to an int here
    os << static_cast<int>(cents);
    return os;
}
