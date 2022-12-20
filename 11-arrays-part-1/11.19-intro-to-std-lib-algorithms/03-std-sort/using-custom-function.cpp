#include <algorithm>
#include <array>
#include <functional> // for std::greater
#include <iostream>

// our custom function to use in std::sort
int greater(int x, int y)
{
    return (x > y); // place the bigger one first(i.e. tell std::sort to sort in
                    // descending order)
}

template <typename T, std::size_t length>
void print(std::array<T, length>& array)
{
    for (const auto& element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array numbers{10, 2, 1, 5, 3, 7, 8};

    std::sort(numbers.begin(),
              numbers.end()); // normal std::sort call, sort in ascending order
    std::cout << "normal std::sort:\n";
    print(numbers);

    // sort using custom function parameter:
    std::sort(numbers.begin(), numbers.end(), greater);
    std::cout << "custom std::sort:\n";
    print(numbers);

    // we can also use std::greater from the 'functional' header instead of
    // writing our own
    std::sort(numbers.begin(), numbers.end(), std::greater{});
    // std::greater is a type, therefore we need to instantiate it instead

    return 0;
}

// a function when used without parantheses is a function pointer