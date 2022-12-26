#include <functional>
#include <iostream>

void myInvoke(const std::function<void()>& fcn)
{
    fcn();
}

int main()
{
    int i{0};

    auto count{[i]() mutable { std::cout << ++i << '\n'; }};

    // to avoid making unintended copies of out lambda, we could ditch captures
    // and use static variables(which is hard to manage and keep track of).
    // or we could wrap it in a std::reference_wrapper, so that copies will be
    // made of the reference instead of the object.
    // syntax: std::ref(lambda variable);
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));

    return 0;
}

// Try to avoid mutable lambdas. Non-mutable lambdas are easier to understand
// and don’t suffer from the above issues, as well as more dangerous issues that
// arise when you add parallel execution.