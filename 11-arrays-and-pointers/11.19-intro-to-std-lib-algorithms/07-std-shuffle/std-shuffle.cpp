#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>

int main()
{
    std::array arr{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // random number generator object mt
    std::random_device rd;
    std::mt19937 mt{rd()};

    // std::shuffle(beginIter,endIter,URBG)
    std::shuffle(arr.begin(), arr.end(), mt);

    // something I don't really understand other than that we iterate over the
    // values while passing them to std::cout which prints the value followed by
    // a space in every iteration
    std::copy(arr.begin(), arr.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // I should be using the range-based-for loop instead:
    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
