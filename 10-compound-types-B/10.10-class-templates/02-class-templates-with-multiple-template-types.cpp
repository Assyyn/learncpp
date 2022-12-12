#include <iostream>

template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

template <typename T, typename U>
void print(const Pair<T, U>& p)
{
    std::cout << '[' << p.first << ',' << p.second << ']';
}

int main()
{
    Pair<int, double> p1{1, 2.3}; // pair holding int and double
    print(p1);

    Pair<char, double> p2{'1', 2.3}; // pair holding char and double
    print(p2);

    Pair<int, int> p3{1, 3}; // pair holding int and int
    print(p3);

    return 0;
}