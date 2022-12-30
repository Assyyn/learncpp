// it is also possible to make an entire class a friend of another class.

// Note: 'friend' is only applied one way, so a class declaring another as its
// friend means that the other class can access its private members but it
// cannot, unless it is also declared as a friend by that class

#include <iostream>

class Circuit;

class Bulb
{
private:
    /// @brief clever trick to make it clear that false==off & on==true
    enum State
    {
        off,
        on,
    };

    State m_state{};

public:
    // by default off
    Bulb(State state = off) : m_state{state} {}

    friend class Circuit; // Circuit is now a friend of Bulb

    friend void printStatus(const Circuit& circuit, const Bulb& bulb);
};

class Circuit
{
private:
    bool m_connected{};

public:
    // by default false
    Circuit(bool connected = false) : m_connected{connected} {}

    void connect(Bulb& bulb);
    void disconnect(Bulb& bulb);

    friend void printStatus(const Circuit& circuit, const Bulb& bulb);
};

// if connected, do nothing. else connect. side effect, bulb turned on
void Circuit::connect(Bulb& bulb)
{
    m_connected = true;
    // bulb's private members are accessible by Circuit and its member(s)
    bulb.m_state = Bulb::on;
}

void Circuit::disconnect(Bulb& bulb)
{
    m_connected = false;
    bulb.m_state = Bulb::off;
}

void printStatus(const Circuit& circuit, const Bulb& bulb)
{
    std::cout << "Circuit is: " << [connected{circuit.m_connected}] {
        return connected ? "connected" : "disconnected";
    }() << '\n';

    std::cout << "Bulb status: " <<
        [state{bulb.m_state}] { return state ? "on" : "off"; }() << '\n';
}

int main()
{
    // by default off
    Bulb bulb{};
    Circuit circuit{};
    printStatus(circuit, bulb);

    // connected
    circuit.connect(bulb);
    printStatus(circuit, bulb);

    // manually disconnected
    circuit.disconnect(bulb);
    printStatus(circuit, bulb);

    return 0;
}