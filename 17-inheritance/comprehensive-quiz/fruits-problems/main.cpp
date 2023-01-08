#include "Apple.h"
#include "Banana.h"
#include "Fruit.h"

#include <iostream>

//
class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple("granny smith apple", "green") {}
};

int main()
{
    Apple a{"red"};
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}