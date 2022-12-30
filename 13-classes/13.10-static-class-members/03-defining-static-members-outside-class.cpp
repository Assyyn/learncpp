#include <iostream>

class IDGenerator
{
private:
    static int s_id;

public:
    static int getNextID();
};

// we don't use 'static' again when defining them outside
int IDGenerator::s_id{0};

int IDGenerator::getNextID()
{
    return s_id++;
}

int main()
{
    // note that we don't need to create an object here, because static member
    // functions don't need an object to be used
    for (int i{0}; i < 5; ++i)
    {
        std::cout << "Next ID is: " << IDGenerator::getNextID() << '\n';
    }
}