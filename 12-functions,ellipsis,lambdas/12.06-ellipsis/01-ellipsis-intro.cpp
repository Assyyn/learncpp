// Ellipsis allow us to pass a variable number of parameters to a function. They
// are rarely used, potentially dangerous, and are to be generally avoided.

// function syntax using ellipsis:
// return_type function_name (argument_list,      ...)
// ^                ^^          ^^       ^         ^
// double         average    (double x, double y, ...)

// An example program:
#include <cstdarg> // needed to use ellipsis
#include <iostream>

// The ellipsis must be the last parameter
// count is how many additional arguments we are passing
double findAverage(int count, ...)
{
    int sum{0};

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start. The first argument is the list
    // to initialize. The second argument is the last non-ellipsis parameter
    va_start(list, count);

    // loop through all the ellipsis values
    for (int arg{0}; arg < count; ++arg)
    {
        // We use va_arg to get values out of our ellipsis
        // The first argument is the va_list we're using
        // The second argument is the type of the value
        sum += va_arg(list, int);
    }

    // Cleanup the va_list when we're done
    va_end(list);

    return static_cast<double>(sum) / count;
}

int main()
{
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

    return 0;
}