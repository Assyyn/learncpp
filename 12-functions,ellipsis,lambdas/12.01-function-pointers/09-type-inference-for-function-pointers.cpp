#include <functional>
#include <iostream>

int foo(int x)
{
    return 10 * x;
}

int main()
{
    // auto can be used to infer the type of a function pointer
    auto fPtr{&foo};
    std::cout << fPtr(10) << '\n'; // 100

    // deducing function pointer type for type aliasing:
    using funcAlias = std::function<decltype(foo)>; // decltype infers the type
                                                    // of the function for us

    funcAlias fncPtr{&foo};
    std::cout << fncPtr(20) << '\n'; // 200

    return 0;
}