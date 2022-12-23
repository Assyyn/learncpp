#include <iostream>
#include <vector>

int main()
{
    // std::vector<int> odd{1,3,5,7,9}; before C++17
    std::vector odd{1, 3, 5, 7, 9};

    // for-each(range-based for loops) can be used with other 'containers'/'data
    // structures'
    for (auto number : odd)
    {
        std::cout << number << '\n';
    }

    std::cout << '\n';

    return 0;
}