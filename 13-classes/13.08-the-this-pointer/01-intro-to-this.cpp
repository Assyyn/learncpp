#include <iostream>

// Consider a class:
class Simple
{
private:
    int m_id;

public:
    Simple(int id) : m_id{id} {}

    void setID(int id)
    {
        m_id = id;
    }

    int getID()
    {
        return m_id;
    }
};

// The this pointer is a hidden const pointer that holds the address of the
// object the member function was called on.
class SimpleV2
{
private:
    int m_id;

public:
    SimpleV2(int id) : m_id{id} {}

    // all non-static member functions have a “this” pointer that refers to the
    // object the function was called on.
    void setID(int id)
    {
        // points to the object's m_id
        this->m_id = id;
    }

    int getID()
    {
        return this->m_id;
    }
};

int main()
{
    Simple simple{1};
    simple.setID(2);
    std::cout << simple.getID() << '\n';

    return 0;
}
