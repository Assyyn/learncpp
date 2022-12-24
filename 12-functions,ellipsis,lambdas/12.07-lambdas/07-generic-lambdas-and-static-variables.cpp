#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// One thing to be aware of is that a unique lambda will be generated for each
// different type that auto resolves to. The following example shows how one
// generic lambda turns into two distinct lambdas:
int main()
{
    // print a value and count how many times @print has been called
    auto print{[](auto value) {
        static int callCount{0};
        std::cout << callCount++ << ':' << value << '\n';
    }};

    print(1); // 0: 1
    print(2); // 1: 2

    print("Hello, World!"); // 0: Hello, World!
    print("Yosh!");         // 1: Yosh!

    print(3); // 2: 3

    return 0;
}

// the two lambdas generated from our generic lambda will not share their static
// variables because they are different lambdas(uhh... )