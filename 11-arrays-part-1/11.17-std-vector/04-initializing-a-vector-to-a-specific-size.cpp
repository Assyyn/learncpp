// Resizing a vector is computationally expensive, so you should strive to
// minimize the number of times you do so. If you need a vector with a specific
// number of elements but don't know the values of the elements at the point of
// declaration, you can create a vector with default elements like so:

#include <iostream>
#include <vector>

int main()
{
    // Using direct initialization, we can create a vector with 5 elements,
    // each element is a 0. If we use brace initialization, the vector would
    // have 1 element, a 5.
    std::vector<int> array(5);

    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}