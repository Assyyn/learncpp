#include <functional>
#include <iostream>

// When std::function is created with a lambda, the std::function internally
// makes a copy of the lambda object.
void myInvoke(const std::function<void()>& fcn)
{
    fcn();
}

int main()
{
    int i{0};

    auto count{[i]() mutable { std::cout << ++i << '\n'; }};

    myInvoke(count);
    myInvoke(count);
    myInvoke(count);

    return 0;
}