#include <iostream>

// enumerators are automatically assigned an integral value based on their
// positions in the enumerator list. the first enumerator is 0 by default
enum Color
{
    black,   // 0
    red,     // 1
    blue,    // 2
    green,   // 3
    white,   // 4
    cyan,    // 5
    yellow,  // 6
    magenta, // 7
};

// it is also possible to explicitly give enumerators custom integral values,
// but is not recommended
enum Animal
{
    cat = -3,
    dog = 24,
    piranha, // it 'follows' the previous enumerator, i.e. piranha=(24+1),
             // so assigned 25
    giraffe = -3,
    lion = 0,
}; // here, 'cat' and 'giraffe' are interchangeable

int main()
{
    Color shirt{blue}; // This actually stores the integral value 2

    // enumerators also implicitly convert to their corresponding integral
    // values
    std::cout << shirt << '\n'; // prints 2

    Animal pet{cat};
    if (pet == giraffe)
    {
        // hmm, it shouldn't do this
        std::cout << "Your pet is a giraffe!\n";
    } // but it does! AVOID such cases!

    std::cout << piranha << '\n'; // prints 25, as expected

    return 0;
}