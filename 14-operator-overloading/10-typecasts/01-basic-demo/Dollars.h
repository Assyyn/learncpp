#pragma once

#include "Cents.h"

class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int dollars = 0) : m_dollars{dollars} {}

    // Allow us to convert Dollars to Cents
    operator Cents() const { return Cents{m_dollars * 100}; }

    // get the raw Dollars, needs explicit casting
    explicit operator int() const { return m_dollars; }
};