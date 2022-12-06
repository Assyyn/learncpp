#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution
#include <chrono> // for std::chrono

int main()
{
    // seed our Mersenne Twister:
    std::mt19937 mt{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};

    // create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6};

    for (int count{1}; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0)
            std::cout << '\n';
    }
    return 0;
}  