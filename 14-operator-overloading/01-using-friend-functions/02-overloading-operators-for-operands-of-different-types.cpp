// We want to make our Rupees class work with integers, so we overload operators
// for the specific operations we want(+,-)

#include <iostream>

class Rupees
{
private:
    int m_rupees{};

public:
    Rupees(int rupees) : m_rupees{rupees} {}

    int getRupees() const
    {
        return m_rupees;
    }

    // overload + to add two "Rupees" objects together
    friend Rupees operator+(const Rupees& a, const Rupees& b);

    friend Rupees operator-(const Rupees& a, const Rupees& b);

    // for two different types, we need to overload both ways
    friend Rupees operator+(const Rupees& a, int b)
    {
        return Rupees{a.m_rupees + b};
    }

    friend Rupees operator+(int a, const Rupees& b)
    {
        return Rupees{a + b.m_rupees};
    }

    // same for '-':

    friend Rupees operator-(const Rupees& a, int b)
    {
        return Rupees{a.m_rupees - b};
    }

    friend Rupees operator-(int a, const Rupees& b)
    {
        return Rupees{a - b.m_rupees};
    }
};

// not a member function:
Rupees operator+(const Rupees& a, const Rupees& b)
{
    return Rupees{a.m_rupees + b.m_rupees};
}

Rupees operator-(const Rupees& a, const Rupees& b)
{
    return Rupees{a.m_rupees - b.m_rupees};
}

int main()
{
    Rupees owned{1000};

    std::cout << "I owned Rs." << owned.getRupees() << " this morning.\n"
              << "I spent 400 on food, which leaves me with Rs."
              << (owned - 400).getRupees() << ".\n"
              << "Oh! Mr.Oot transferred me Rs.15! Then I have Rs."
              << (15 + owned - 400).getRupees() << " now.\n";

    return 0;
}