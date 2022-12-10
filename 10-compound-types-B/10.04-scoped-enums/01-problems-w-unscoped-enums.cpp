#include <iostream>

enum Sport
{
    football,
    cricket,
    handball,
};

enum Genre
{
    rock,
    pop,
    rnb,
};

int main()
{
    Sport sport{football};
    Genre genre{rock};

    // now consider this:
    if (sport == genre)
    {
        std::cout
            << "sport and genre are equal!\n"; // hmm, why does this execute?
    }
    else
    {
        std::cout << "sport and genre are not equal\n";
    }

    return 0;
}

// the issue is that both Sport and Genre are represented by integral types,
// resulting in comparisions between them being both valid and semantically
// meaningless. (are sport and genre the same thing?) so enum classes are
// introduced