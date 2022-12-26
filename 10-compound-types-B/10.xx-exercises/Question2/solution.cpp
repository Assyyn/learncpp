#include <iostream>

template <typename T>
struct Triad
{
    T first{};
    T second{};
    T third{};
};

template <typename T>
void print(Triad<T> x)
{
    std::cout << '[' << x.first << ',' << x.second << ',' << x.third << ']';
}

int main()
{
    Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{1.33, 2.1, 3.0}; // note: uses CTAD to deduce template arguments
    print(t2);

    Triad t3{"Hi", "Hello", "Bon dia"};
    print(t3);

    return 0;
}