#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    // the first 2 numbers in the series are known and defaults
    std::vector<int> fibonacci{};

    fibonacci.reserve(13); // ask for memory to hold 13 integers, we are
                           // printing 13 fibonacci numbers in this program

    fibonacci = {0, 1}; // assigned here to prevent an unnecessary resize()

    for (int n{0}; n < 13; ++n)
    {
        std::cout << fibonacci[n] << ' ';

        if (n > 0 && n < 12)
            fibonacci.push_back(fibonacci.at(n) + fibonacci.at(n - 1));
    }

    std::cout << "\nsize: " << std::size(fibonacci);

    return 0;
}