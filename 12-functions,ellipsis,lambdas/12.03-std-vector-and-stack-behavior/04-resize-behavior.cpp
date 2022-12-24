#include <iostream>
#include <vector>

// the vector may allocate more capacity than is needed when it resizes. This is
// done in expectation that more data will be pushed into it, so that the number
// of resize operations can be minimized.

int main()
{
    std::vector v{0, 1, 2, 3, 4};
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';

    v.push_back(5); // add another element
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';

    return 0;
}

// On my machine, this prints:
// size: 5 cap: 5
// size: 6 cap: 10