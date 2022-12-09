#include <iostream>

int main()
{
    int x{3};
    int y{4};

    int &ref{x};
    // references cannot be reseated (bound to another variable/object) 
    ref = y;    // all this really does is behave like x. so what happens is: x = 4
    //do something

    std::cout << x << '\n'; // prints 4, quite unsurprisingly

    return 0;
}