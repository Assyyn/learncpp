#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ranges>

template <typename T, std::size_t size>
void print(std::array<T, size>& arr)
{
    for (const auto& elem : arr)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

void decrement(int& x)
{
    --x;
}

int main()
{
    std::array arr{2, 4, 6, 8, 10, 12};

    std::for_each(arr.begin(), arr.end(), decrement);
    print(arr);

    // since C++20:
    std::ranges::for_each(arr, decrement);
    print(arr);

    // we can also skip some elements of the container
    // don't decrement first and the last element:
    std::for_each(std::next(arr.begin()), std::prev(arr.end()), decrement);
    print(arr);

    return 0;
}