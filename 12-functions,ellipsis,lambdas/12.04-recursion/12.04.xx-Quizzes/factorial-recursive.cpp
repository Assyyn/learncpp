#include <iostream>

/* Factorial definition:
    f(n) = n*(n-1)*(n-2)*(n-3)* ... ... *3*2*1
*/

int factorial(int n)
{
    if (n <= 0) // base case
        return 1;

    return factorial(n - 1) * n;
}

int main()
{
    for (int count{0}; count < 7; ++count)
    {
        std::cout << factorial(count) << ' ';
    }

    return 0;
}