#include "Person.h"
#include "Student.h"

#include <iostream>

int main()
{
    Student susan{"Susan Moore", 24, 1};
    Person jack{"Jack Hughes", 30};

    // works as expected
    std::cout << jack << '\n';
    std::cout << susan << '\n'; // the override works!

    return 0;
}