#include <iostream>
#include <random>

namespace Random // capital R to avoid namespace collisions
{
    std::mt19937 mt{std::random_device{}()};

    int get(int min, int max)
    {
        std::uniform_int_distribution die{min, max};
        return die(mt);
    }
}

int main()
{
    std::cout << Random::get(1, 10) << '\n';
    std::cout << Random::get(11, 20) << '\n';

    return 0;
} // in this method, while useful,mt is heavily underseeded. essentially initializing a 624-byte object with a 4-byte value