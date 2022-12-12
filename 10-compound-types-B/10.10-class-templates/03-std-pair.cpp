#include <iostream>
#include <utility> // contains std::pair

template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << '[' << p.first << ',' << p.second << ']';
}

int main()
{
    std::pair<int, char> p{1, '2'};
    print(p);

    return 0;
}