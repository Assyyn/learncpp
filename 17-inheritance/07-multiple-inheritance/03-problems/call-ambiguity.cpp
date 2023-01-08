#include <iostream>

// Ambiguity can result when multiple base classes contain a function with the
// same name. For example:
class USBDevice
{
private:
    long m_id{};

public:
    USBDevice(long id) : m_id{id} {}

    long getID() const { return m_id; }
};

class NetworkDevice
{
private:
    long m_id{};

public:
    NetworkDevice(long id) : m_id{id} {}

    long getID() const { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId) :
        USBDevice{usbId}, NetworkDevice{networkId}
    {}
};

int main()
{
    WirelessAdapter c54G{5442, 181742};
    std::cout << c54G.getID(); // Which getID() do we call?

    // we can workaround this using explicit calls to specific inherited member
    // functions from parent classes
    std::cout << c54G.USBDevice::getID();

    return 0;
}