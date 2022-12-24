#include <functional>
#include <iostream>

// In cases where the actual lambda is unknown (e.g. because we’re passing a
// lambda to a function as a parameter and the caller determines what lambda
// will be passed in), we can’t use auto without compromises. In such cases,
// std::function can be used instead.

// we don't know what fn will be. std::function works with both functions and
// lambdas
void repeat(int repititions, const std::function<void(int)>& fn)
{
    for (int i{0}; i < repititions; ++i)
    {
        fn(i);
    }
}

int main()
{
    // store the lambda and pass it,
    std::function<void(int)> printNum{[](int n) { std::cout << n << ' '; }};
    repeat(3, printNum);

    // or directly pass it:
    repeat(3, [](int n) { std::cout << n << ' '; });

    return 0;
}

// Use auto when initializing variables with lambdas, and std::function if you
// can’t initialize the variable with the lambda, and also when you want them to
// be separated to a header and source file.