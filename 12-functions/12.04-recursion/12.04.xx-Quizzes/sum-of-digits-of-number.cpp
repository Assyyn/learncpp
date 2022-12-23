#include <iostream>

// 1234 -> 1+2+3+4 = 10

int sumOfDigits(int n)
{
    if ((n / 10) == 0) // base case(1-digit number)
        return n;

    return sumOfDigits(n / 10) + (n % 10);
}

int main()
{
    std::cout << sumOfDigits(93427);

    return 0;
}