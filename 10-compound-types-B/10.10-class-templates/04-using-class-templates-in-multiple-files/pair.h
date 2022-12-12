#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

template <typename T>
constexpr T max(Pair<T, T> p)
{
    return (p.first > p.second) ? p.first : p.second;
}

#endif