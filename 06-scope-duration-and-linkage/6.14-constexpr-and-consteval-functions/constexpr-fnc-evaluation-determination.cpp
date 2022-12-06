#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

constexpr int doSomething(int x)
{
    if(std::is_constant_evaluated())  
        return x;   // compile-time eval
    else 
        return -1;  // runtime eval
}

int main()
{
    constexpr int x{32};

    constexpr int result {doSomething(x)};
    std::cout << result << '\n';    // prints 32
    std::cout << doSomething(x) << '\n';    // prints -1
    std::cout << doSomething(x) << '\n';    // could print 32 or -1

    return 0;
}