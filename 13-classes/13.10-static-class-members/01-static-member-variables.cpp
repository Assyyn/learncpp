#include <iostream>
#include <string>

class Player
{
private:
    //  a static const int can be declared and initialized directly
    static inline int s_m_id{1};

    // const members can only be initialized once(immutability)
    static const inline int s_value{4}; // a static inline int can be declared
                                        // and initialized directly (C++17)

    std::string m_username{};
    int m_id{};

    void setup()
    {
        m_id = s_m_id++;
    }

public:
    // every player will have different id
    Player() : m_id{s_m_id++} {}

    // this really just brings redundancy to code, maybe make a setup() function
    Player(const std::string name) : m_username{name}, m_id{s_m_id++} {}

    // with setup() function
    // Player(const std::string name): m_username{name}{setup();}

    int getID() const
    {
        return m_id;
    }
};

class Ex2
{
private:
    static int e2;
};

// Access static members by class name (using the scope resolution operator)
// rather than through an object of the class (using the member selection
// operator).

// need: typename.
// accessible even if private or protected using Class::s_variable syntax
// because its a definition. cannot: direct/uniform initialize
int Ex2::e2 = 20;

int main()
{
    Player p1{};
    std::cout << p1.getID() << '\n';

    using namespace std::string_literals;
    Player p2{"yuukie"s};
    std::cout << p2.getID() << '\n';
}