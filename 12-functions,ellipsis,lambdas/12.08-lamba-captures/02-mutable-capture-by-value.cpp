#include <algorithm>
#include <array>
#include <iostream>

// the syntax: [capture-variable] (parameters) mutable {}; can be used to allow
// the lambda to modify the copy(note that only the copy gets changed)

int main()
{
    std::array<int, 4> arr{1, 2, 3, 4};

    std::cout << "Pick a number: ";
    int n{};
    std::cin >> n;

    // we want to print out the array elements, multiplied by user-supplied
    // number(which decrements each time), using a lambda
    auto customMult{
        [n](int x) mutable { std::cout << n << ':' << (n--) * x << ' '; }};

    // Because captured variables are members of the lambda object, their values
    // are persisted across multiple calls to the lambda! this is shown by the
    // fact that the captured n gets decremented each time the lambda is called
    std::for_each(arr.begin(), arr.end(), customMult);
    std::cout << '\n';

    // the original value of n is still intact:
    std::cout << "n=" << n << '\n';

    return 0;
}