// Command line arguments are always passed as strings, even if the value
// provided is numeric in nature. To use a command line argument as a number,
// you must convert it from a string to a number

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        // On some operating systems, argv[0] can end up as an empty string
        // instead of a program's name.
        // We'll conditionalize our response on whether argv[0] is empty or not
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }

    std::stringstream convert{
        argv[1]}; // set up a stringstream variable named convert, initialized
                  // with the input from argv[1]

    int myint{};
    if (!(convert >> myint)) // do the conversion
        myint = 0; // if conversion fails, set myint to a  default value

    std::cout << "Got integer: " << myint << '\n';

    return 0;
}

// Command line arguments provide a great way for users or other programs to
// pass input data into a program at startup. Consider making any input data
// that a program requires at startup to operate a command line parameter. If
// the command line isn’t passed in, you can always detect that and ask the user
// for input. That way, your program can operate either way.