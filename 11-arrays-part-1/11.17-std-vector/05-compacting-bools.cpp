// std::vector has another cool trick up its sleeves. There is a special
// implementation for std::vector of type bool that will compact 8 booleans into
// a byte!

#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> array{true, false, false, true, true};
    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}