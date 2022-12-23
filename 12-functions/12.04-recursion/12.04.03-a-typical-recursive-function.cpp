#include <iostream>

// return the sum of all the integers between 1(inclusive) and sumto(inclusive)
// returns 0 for negative numbers
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case(termination condition) when user passed in an
                  // unexpected argument
    if (sumto == 1)
        return 1; // normal base case (termination condition)

    return sumTo(sumto - 1) + sumto; // recursive function call
}

int main()
{
    std::cout << "sum upto 10(from 1): " << sumTo(10) << '\n'; // 55

    return 0;
}