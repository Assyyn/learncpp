#include <iostream>

// print the binary representation of given number using recursive function

void printBinary(unsigned int n)
{
    if (n == 0) // termination case
        return;

    printBinary(n / 2);

    std::cout << n % 2;
}

int main()
{
    int n{};
    std::cin >> n;
    printBinary(static_cast<unsigned int>(n));

    return 0;
}