#include <iostream>
#include <string>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(const Pair<T>& x)
{
    return (x.first > x.second) ? x.first : x.second;
}

int main()
{
    Pair A{2.4, 5.6};
    std::cout << max(A) << '\n';

    Pair B{'c', 'd'};
    std::cout << max(B) << '\n';

    { // explicit use of std::string_literals to use strings in a Pair without
      // making std::string objects
        using namespace std::string_literals;
        Pair C{"Harry"s, "John"s};
        std::cout << max(C) << '\n';
    }

    // string literals implicitly converted to std::string
    Pair<std::string> D{"Hi", "Hello"};
    std::cout << max(D) << '\n';

    return 0;
}