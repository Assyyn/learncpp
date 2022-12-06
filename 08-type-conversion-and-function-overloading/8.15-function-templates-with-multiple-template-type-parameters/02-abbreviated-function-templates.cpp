#include <iostream>

auto max(auto x, auto y) // C++20 feature: abbreviated function template
{
    return (x > y ? x : y);
}

// the above template is the same as:
template <typename T, typename U>
auto max(T x, U y)
{
    return (x > y ? x : y);
}
// but is more concise and readable
// prefer it when you want each template type parameter to be an independent type

// the following template is not produce-able using abbreviated function templates
template <typename T>
T sum(T x, T y)
{
    return x + y;
}

// using abbreviated function templates would lead to the following equivalent template to be used
template <typename T, typename U>
auto sum(T x, T y)
{
    return x + y;
}
// for obvious reasons