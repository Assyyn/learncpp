#include <iostream>

/* Mathematical definition of fibonacci numbers
    F(n)=  0 if n = 0
        =  1 if n = 1
        =  f(n-1)+f(n-2) if n>1
*/

// calculate the nth fibonacci number
int fibonacci(int count)
{
    if (count == 0) // base case
        return 0;
    if (count == 1) // base case
        return 1;

    return fibonacci(count - 1) + fibonacci(count - 2);
}

int main()
{
    // print 13 fibonacci numbers
    for (int count{0}; count < 13; ++count)
    {
        std::cout << fibonacci(count) << ' ';
    }

    return 0;
}

// the above example calls fibonacci() 1205 times!