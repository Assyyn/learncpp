// Iterators can also be left dangling

#include <iostream>
#include <vector>

int main()
{
    std::vector v{1, 3, 5, 7, 9};

    auto it{v.begin()};

    ++it;                     // move to second element
    std::cout << *it << '\n'; // ok: prints 2

    v.erase(it); // erase the element currently being iterated over

    // erase() invalidates iterators to the erased element (and subsequent
    // elements) so iterator "it" is now invalidated

    ++it; // undefined behavior
    std::cout << *it << '\n';

    return 0;
}