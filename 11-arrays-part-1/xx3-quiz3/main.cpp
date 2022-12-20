// Write your own function to swap the value of two integer variables.
// Write a main() function to test it.

#include <iostream>
#include <iterator>

// using pointers
template <typename T>
void swap(T* a, T* b)
{
    T temp{*a};
    *a = *b;
    *b = temp;
}

// using references
template <typename T>
void swapR(T& a, T& b)
{
    T temp{a};
    a = b;
    b = temp;
}

int main()
{
    int x{2};
    int y{3};
    std::cout << "x: " << x << ' ' << "y: " << y << "\n\n";

    swap(&x, &y);
    std::cout << "After swap(x,y):\n";
    std::cout << "x: " << x << ' ' << "y: " << y << "\n\n";

    swapR(x, y);
    std::cout << "After swapR(x,y):\n";
    std::cout << "x: " << x << ' ' << "y: " << y << '\n';

    return 0;
}