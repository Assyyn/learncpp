// resizing a std::vector is as simple as calling the resize() function

#include <iostream>
#include <vector>

int main()
{
    std::vector array{0, 1, 2};
    array.resize(5); // set size to 5

    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
    {
        std::cout << i << ' ';
    }
    // when we resized the vector, the existing element values were preserved

    // new elements are initialized to the default value for the type (which is
    // 0 for integers).

    std::cout << '\n';

    // we can also resize a vector to be smaller:
    array.resize(1); // set length to 1

    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}