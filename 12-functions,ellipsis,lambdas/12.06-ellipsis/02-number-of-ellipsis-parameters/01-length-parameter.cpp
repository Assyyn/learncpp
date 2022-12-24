#include <cstdarg> // needed to use ellipsis
#include <iostream>

double findAverage(int count, ...)
{
    int sum{0};

    std::va_list list;

    va_start(list, count);

    for (int arg{0}; arg < count; ++arg)
    {
        sum += va_arg(list, int);
    }

    va_end(list);

    return static_cast<double>(sum) / count;
}

int main()
{
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

    // what could possibly go wrong?
    std::cout << findAverage(6, 1.0, "Hello,World!", 3, 4, 5, 6) << '\n';
    // the compiler will happily allow you to pass in variables of any type!
    // classic 'GIGO' example

    // ellipsis don't know how many parameters were passed!
    std::cout << findAverage(2, 9, 10, 12, "Hey", 8.90) << '\n';
    std::cout << findAverage(3, 1)
              << '\n'; //-> reads in garbage value for the
                       // last two integers it was expecting, but never got.
                       // Consequently produces garbage result

    return 0;
}