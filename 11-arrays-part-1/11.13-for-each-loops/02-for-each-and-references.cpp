#include <iostream>
#include <string>

int main()
{
    std::string array[]{"Harry", "Sam", "Joe"};
    for (auto element : array)
    {
        std::cout << element << '\n';
    }
    // since every iteration, element will copy the array elements, it is quite
    // expensive. Most of the time, we may also want to perform operations on
    // our array elements. For such purposes and benefits, it is a good idea to
    // make 'element' a reference(and const when you want read only access)
    for (auto& element : array) // make some changes to the elements
    {
        element += ". Changed through a for-each ><";
    }

    // if we do not want to change elements:
    for (const auto& element : array)
    {
        std::cout << element << '\n';
    }

    return 0;
}