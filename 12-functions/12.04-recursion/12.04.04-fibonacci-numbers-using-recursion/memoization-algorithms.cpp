// One technique to reduce the number of calls necessary for recursive functions
// to generate the result is called Memoization

// The Memoization technique caches the results of expensive function calls so
// the result can be returned when the same input occurs again.

// Memoized version of the recursive fibonacci algorithm

#include <iostream>
#include <vector>

int fibonacci(int count)
{
    // We'll use a static std::vector to cache calculated results
    static std::vector results{0, 1};

    // If we've already seen this count, then use the cached result
    if (count < static_cast<int>(std::size(results)))
        return results[count];

    // Otherwise calculate new result and add it to the cache
    results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
    return results[count];
}

int main()
{
    // display the first 13 Fibonacci numbers
    for (int count{0}; count < 13; ++count)
    {
        std::cout << fibonacci(count) << '\n';
    }

    return 0;
}

// the memoized function makes 35 function calls, which is much better than the
// 1205 of the un-memoized algorithm