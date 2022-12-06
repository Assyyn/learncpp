#include <iostream>
#include <random>

int main()
{
    // Seed using random_device
    std::mt19937 mt{std::random_device{}()};

    std::uniform_int_distribution die6{1,6};

    for(int count{1}; count <=50; ++count)
    {
        std::cout << die6(mt) << '\t';

        if(count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}   // prefer this std::random_device over using chrono wherever possible