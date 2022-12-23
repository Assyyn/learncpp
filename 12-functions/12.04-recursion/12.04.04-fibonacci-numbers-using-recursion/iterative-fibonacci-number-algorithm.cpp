#include <iostream>

/* Mathematical definition of fibonacci numbers
    F(n)=  0 if n = 0
        =  1 if n = 1
        =  f(n-1)+f(n-2) if n>1
*/

// an iterative method to find nth fibonacci number
int fibonacci(int count)
{
    int x{0};      // f(n-2)
    int y{1};      // f(n-1)
    int result{0}; // f(n)

    for (int i{0}; i <= count; ++i)
    {
        // f(n) = f(n-1) + f(n-2)
        result = result + x;
        x = y;
        y = result;
    }

    return result;
}

int main()
{
    // print first 13 fibonacci numbers
    for (int count{0}; count < 13; ++count)
        std::cout << fibonacci(count) << ' ';

    return 0;
}