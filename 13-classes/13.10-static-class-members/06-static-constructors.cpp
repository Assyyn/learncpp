// static constructors are not supported in C++, but we could use the following
// techniques to initialize static member variables of our class:

#include <iostream>
#include <random>
#include <vector>

// Construction by using a nested initializing class:
class RandomNumber
{
private:
    static inline std::mt19937 s_mt;

    // can initialize s_mt by using init_mt's constructor
    class init_mt
    {
    public:
        init_mt()
        {
            std::random_device rd;
            // warmup and handle underseeding
            std::seed_seq ssq{rd(), rd(), rd(), rd(), rd(), rd(), rd()};

            s_mt = std::mt19937{ssq};
        }
    };

    // to make sure s_mt gets seeded
    static inline init_mt s_initializer{};

public:
    static int RandomInRange(int from, int thru)
    {
        std::uniform_int_distribution range{from, thru};
        return range(s_mt);
    }
};

// Construction using lambda expression:
// used when you cannot list initialize the std::vector, or where direct
// initialization is not possible
class Something
{
private:
    // make a copy of the std::vector we really want inside the lambda
    // expression, and return it. then initialize our static vector with it
    // using braced initialization
    static inline std::vector<char> s_chars{
        [] { return std::vector<char>{}; }()};
};

int main()
{
    for (int i{1}; i < 21; ++i)
    {
        std::cout << RandomNumber::RandomInRange(1, 9) << ' ';
        if (i % 10 == 0)
            std::cout << '\n';
    }
}