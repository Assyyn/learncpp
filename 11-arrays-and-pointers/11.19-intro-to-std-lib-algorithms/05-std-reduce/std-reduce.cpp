#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>

// std::reduce applies a function, by default the + operator, to all elements in
// a list, resulting in a single value. When we use the + operator, the result
// is the sum of all elements in the list

int main()
{
    std::array nums{1, 3, 5, 7, 9};

    auto x{std::reduce(nums.begin(), nums.end())};
    std::cout << "default std::reduce\n"
              << "sum: " << x << '\n';

    return 0;
}