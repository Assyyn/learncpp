#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()}; // get 8 integers of random numbers from std::random_device for our seed
    std::mt19937 mt{ss};                                              // initialize out Mersenne Twister with the std::seed_seq

    std::uniform_int_distribution die{0, 100};

    for (int i{1}; i <= 100; ++i)
    {
        std::cout << die(mt) << '\t';

        if (i % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}
// std::seed_seq attempts to fill the seed values to initialize our PRNG
// other methods:
// use other "random" inputs to std::seed_seq, like from the clock etc
// use a different PRNG with a smaller state.

// warming up a PRNG:   (Pseudo Random Number Generator)
// when a PRNG is underseeded, the initial results may not be high quality. 
// "warming up" is essentially discarding the first N results to ensure that our results are of the best quality that can be produced
// typically, a few hundred or thousand results are discarded
// period of PRNG is directly proportional to the number of results discarded
// std::seed_seq initialization used by std::mt19937 performs a warm up, so no need of explicit warming up std::19937 objects