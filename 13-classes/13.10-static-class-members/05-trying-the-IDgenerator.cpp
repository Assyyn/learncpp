// Trying the IDGenerator class to assign unique IDs to players, suggestions and
// criticisms welcome

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

// generate UUID(could do better)
class IDGenerator
{
private:
    // s_id is not guaranteed to be unique for all possible values
    static inline int s_id{0};
    // class to  generate a random number, nested because its only going to be
    // used here
    class RandomNumber
    {
    private:
        class URNG
        {
        public:
            static inline std::mt19937 s_mt{static_cast<unsigned int>(
                std::chrono::steady_clock::now().time_since_epoch().count())};
        };

    public:
        static inline int getRandomNumber(int from, int thru)
        {
            std::uniform_int_distribution range(from, thru);
            return range(URNG::s_mt);
        }
    };

public:
    static inline int getNextID()
    {
        // between 1-10 because we don't want to run into problems with overflow
        // anytime soon, and also not have to deal with resetting the ID
        // counter(which would lead to needing to implement uniqueness checks or
        // some other thing)
        // we could always just do increments and return, but anyways..
        return s_id += RandomNumber::getRandomNumber(1, 10);
    }
};

// works
void checkRandomness()
{
    for (int i{0}; i < 10; ++i)
    {
        int x{IDGenerator::getNextID()};
        int y{IDGenerator::getNextID()};
        std::cout << x << ',' << y << '\t' << "y-x=" << y - x << '\n';
    }
}

// contains username and id
// on second thought, maybe could nest the IDGenerator inside this(but idt
// that's a good idea(?))
// would prevent IDGenerator::getNextID() from being accessible from the global
// namespace(or rather just at all, by having it be a private member)
class Player
{
private:
    std::string m_username{};
    const int m_id{};

public:
    // use the generator to assign immutable IDs to every new player
    Player(const std::string_view username) :
        m_username{username}, m_id{IDGenerator::getNextID()}
    {
        // check if username is invalid
        auto found{std::find(username.begin(), username.end(), ' ')};
        if (found != username.end())
            throw std::runtime_error("username cannot have spaces");
    }

    // function is const by best practice
    void print() const
    {
        std::cout << "Username: " << m_username << '\n'
                  << "ID: " << m_id << '\n';
    }
};

int main()
{
    const Player p1{"yuki"};
    p1.print();

    Player ai{"AI"};
    ai.print();

    // Note that the function is still global, and can generate numbers anywhere
    std::cout << IDGenerator::getNextID() << '\n';
    // can be remedied depending on if it really needs to be inaccessible here

    using namespace std::string_literals;
    Player p2{"mio"s};
    p2.print();

    // invalid object example:
    // Player invalid{"hi hi"s};
    // invalid.print();

    return 0;
}