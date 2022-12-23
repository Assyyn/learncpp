// A program to print the value of all command line arguments

#include <iostream>

// argc will always be atleast 1, because the first argument is always the name
// of the program itself
int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments.\n";

    // Loop through each argument and print its number and value
    for (int count{0}; count < argc; ++count)
    {
        std::cout << '#' << count << ' ' << argv[count] << '\n';
    }

    return 0;
}

// Argument 0 is the path and name of the current program being run.