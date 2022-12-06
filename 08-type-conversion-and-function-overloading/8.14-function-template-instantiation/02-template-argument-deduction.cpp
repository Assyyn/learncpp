#include <iostream>

template <typename T>
T max(T x, T y)
{
    std::cout << "called max<T>(T,T)\n";
    return (x > y ? x : y);
}

int max(int x, int y)
{
    std::cout << "called max(int,int)\n";
    return (x > y ? x : y);
}

int main()
{
    int x{9};
    int y{10};
    std::cout << max<int>(x, y) << '\n'; // 10

    // we can instead do this, which is called template-argument-deduction
    // will only consider max<int> template function overloads
    std::cout << max(x, y) << '\n'; // called max<T>(T,T)
                                    // 10

    // or this, which will consider both max<int> template function and max non-template function overloads
    std::cout << max<>(x, y) << '\n'; // called max(int,int)
                                      // 10

    return 0;
}

// best practice: favor normal function call syntax when using function templates