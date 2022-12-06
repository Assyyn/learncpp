#include <iostream>

int main()
{
    std::cout << "Enter two integers: ";
    int smaller {}, larger {};
    std::cin >> smaller >> larger;

    if(smaller>larger)
    {
        int temp {larger};
        std::cout << "Swapping the values\n";
        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller value is: " << smaller << '\n'; 
    std::cout << "The larger value is: " << larger << '\n';

    return 0;
}