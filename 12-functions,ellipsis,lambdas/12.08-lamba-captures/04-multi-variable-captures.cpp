#include <iostream>

int main()
{
    int x{0};
    double y{2.5};

    // we can capture multiple variables by separating them with a comma.
    auto printVars{
        [x, &y]() { // we can capture each variable in any way we want
            std::cout << "x->" << x << '\t' << "y->" << (y--) << '\n';
        }};

    for (int n{0}; n < 3; ++n)
    {
        printVars();
    }

    return 0;
}