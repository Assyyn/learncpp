#include <iostream>

void addAndPrint(auto x, auto y) // would result in an error prior to c++20
// in c++20, it triggers function template
{
    std::cout << x + y << '\n';
}

int main()
{
    addAndPrint(3, 4);       // 7
    addAndPrint(3.9l, 2.0l); // 5.9
}