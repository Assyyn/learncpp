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
    // momo is Nepal's most beloved fast food(?)
    Rupees perPlateMomo{120};
    // Chiso -> drinks
    Rupees perChiso{60};

    std::cout << "I spent Rs." << (perChiso + perPlateMomo).getRupees()
              << " on momo and chiso.\n";

    std::cout << "Momo is costs Rs." << (perPlateMomo - perChiso).getRupees()
              << " more than chiso here.\n";

    return 0;
}