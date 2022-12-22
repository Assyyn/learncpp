// We will be using function pointers throughout this quiz

#include <cassert>
#include <functional>
#include <iostream>

/* 1a) Create a short program asking the user for two integer inputs and a
 * mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid
 * operation.*/

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '/', '*'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

/* 1b) Write functions named add(), subtract(), multiply(), and divide(). These
 * should take two integer parameters and return an integer.*/
int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

int subtract(int x, int y)
{
    return x - y;
}

int divide(int x, int y)
{
    return x / y;
}

/* 1c) Create a type alias named ArithmeticFunction for a pointer to a function
 * that takes two integer parameters and returns an integer. Use std::function,
 * and include the appropriate header.*/
using ArithmeticFunction = std::function<int(int, int)>;

/* 1d) Write a function named getArithmeticFunction() that takes an operator
 * character and returns the appropriate function as a function pointer.*/
ArithmeticFunction getArithmeticFunction(const char op)
{
    switch (op)
    {
        case '+':
            return &add;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
    }

    return nullptr;
}

/* 1e) Modify your main() function to call getArithmeticFunction(). Call the
 * return value from that function with your inputs and print the result.*/

int main()
{
    int x{getInteger()};
    char op{getOperation()};
    int y{getInteger()};

    ArithmeticFunction calculate{getArithmeticFunction(op)};
    if (calculate)
        std::cout << x << op << y << '=' << calculate(x, y) << '\n';

    return 0;
}