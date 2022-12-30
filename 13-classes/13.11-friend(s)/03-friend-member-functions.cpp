// Instead of making an entire class a friend, you can make a single member
// function a friend. This is done similarly to making a normal function a
// friend, except using the name of the member function with the
// className:: prefix included

// Note that it is generally cleaner to write separate .h/.cpp combinations for
// classes and write our main program in a separate .cpp file for various
// reasons such as avoiding conflicting cases that may arise when making member
// functions of another class 'friend's. 'Clean' also translates to separating
// interfaces and implementation details

// Example code:
#include <iostream>

// forward declaration for the Storage class
class Storage;

class Display
{
private:
    bool m_displayIntFirst{};

public:
    Display(bool displayIntFirst) : m_displayIntFirst{displayIntFirst} {}

    // declare only; compile doesn't know what the Storage class looks like at
    // this point
    void displayItem(const Storage& storage);
};

class Storage
{
private:
    int m_nValue{};
    double m_dValue{};

public:
    Storage(int nValue, double dValue) : m_nValue{nValue}, m_dValue{dValue} {}

    // make Display::displayItem member function a friend of the Storage class
    friend void Display::displayItem(const Storage& storage);
};

// Note that making a specific member function a friend requires the full
// definition for the class of the member function to have been seen first.
// Which is why we defined this function after defining the Storage class
void Display::displayItem(const Storage& storage)
{
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

int main()
{
    Storage storage{4, 5.6};
    Display display{false};

    display.displayItem(storage);

    return 0;
}