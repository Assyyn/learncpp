#include <iostream>

int main()
{
    int terms{10};

    {
        std::cout << terms << '\n'; // outputs 10

        int terms{5}; // perfectly legal, 'terms' now refers to this within the local scope

        std::cout << terms << '\n'; // outputs 5

        terms = 12;

        std::cout << terms << '\n'; // outputs 12
    }                               // nested block terms is destroyed

    std::cout << terms << '\n'; // outputs 10

    return 0;
} // outer block terms destroyed

// best practice: avoid variable shadowing