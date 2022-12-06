#include <iostream>

// lifetime of referents to their references are 'largely' independent
int main()
{
    int x{20};

    {
        int &refX{x};
        std::cout << refX << '\n'; // 20
    }                              // refX is destroyed here - does not impact x

    std::cout << x << '\n'; // 20

    return 0;
} // x is destroyed here

// Dangling references - references whose referents are destroyed before them, covered in 9.11