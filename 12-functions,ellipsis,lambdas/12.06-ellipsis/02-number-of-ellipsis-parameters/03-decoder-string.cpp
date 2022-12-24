#include <cstdarg>
#include <iostream>
#include <string_view>

double findAverage(std::string_view decoder, ...)
{
    double sum{0};

    // we can keep track of how many valid summations happened to get correct
    // average values, while maintaining the ability to ignore unintended
    // code-types
    int count{0};

    // declare va_list
    std::va_list list;

    // make list point to the ellipsis
    va_start(list, decoder);

    // the characters in the decoder-string provide the data-types of
    // each ellipsis parameter. The loop runs for the length of the decoder
    for (auto codetype : decoder)
    {
        // parameters corresponding to current code-type are added to sum
        // ignore any other type for now.
        switch (codetype)
        {
            case 'i':
                sum += va_arg(list, int);
                count += 1;
                break;

            case 'd':
                sum += va_arg(list, double);
                count += 1;
                break;
            default: // read as string, discard
                va_arg(list, char*);
                break;
        }
    }

    // cleanup list
    va_end(list);

    return sum / count;
}

int main()
{
    std::cout << findAverage("iis", 1, 2, "hi") << '\n';

    std::cout << findAverage("iidid", 1, 2, 3.0, 9, 12.4) << '\n';
    std::cout << findAverage("dddi", 3.4, 5.2, 9.88, 10) << '\n';

    std::cout << findAverage("ssidsi", 'x', '1', 5, 5.0, "hi", 10) << '\n';

    // it can still produce garbage results due to sloppy calls:
    std::cout << findAverage("id", 5, 5) << '\n';
    // we expect it to return a 5, but instead get 2.5 as the
    // result, because we passed in an int instead of the double that is
    // mentioned in the decoder string

    return 0;
}