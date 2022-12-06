#include <iostream>
#include <limits> //for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} // ignore everything up to and including the next '\n' character

double getDouble()
{
    while (true)
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        if (!std::cin) // has previous extraction failed?
        {
            // yep, let's handle it
            std::cin.clear(); // put us back into normal state
            ignoreLine();     // and remove the bad input
            std::cerr << "Oops, that input is invalid. Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;
        default:
            std::cerr << "Oops, that input is invalid. Please try again.\n";
        }
    }
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default:
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main()
{
    double x{getDouble()};
    char operation{getOperator()};
    double y{getDouble()};

    printResult(x, operation, y);

    return 0;
}