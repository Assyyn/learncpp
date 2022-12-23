// An iterator is an object designed to traverse through a container, providing
// access to each element along the way.

#include <array>
#include <iostream>
#include <iterator> // for std::begin and std::end

int main()
{
    std::array array{1, 2, 3};

    // Ask our array for the begin and end points (via the begin and end member
    // functions)
    auto begin{array.begin()};
    auto end{array.end()};

    for (auto p{begin}; p != end; ++p) // ++ to move to next element
    {
        std::cout << *p << ' '; // Indirection to get value of current element
    }
    std::cout << '\n';

    // using std::begin and std::end:
    begin = std::begin(array);
    end = std::end(array);

    // see if std::end and array.end() return the same value:
    if (std::end(array) == array.end())
        std::cout << "They return the same value\n";

    return 0;
}