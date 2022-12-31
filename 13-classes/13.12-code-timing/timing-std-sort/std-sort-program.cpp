#include "Timer.h"

#include <algorithm> // for std::sort
#include <array>
#include <iostream>
#include <numeric> // for std::iota
#include <ranges>

// takes an average of 0.000175 seconds on my machine with  flags: -O2 -DNDEBUG

constexpr int g_arrayElements{10000};

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(),
              1); // fill the array with values 10000 to 1

    Timer t;

    std::ranges::sort(array); // Since C++20
    // If your compiler isn't C++20-capable
    // std::sort(array.begin(), array.end());

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}