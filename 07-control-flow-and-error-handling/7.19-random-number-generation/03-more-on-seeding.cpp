#include <iostream>
#include <random>

int getCard()
{
    std::mt19937 mt{std::random_device{}()}; // this gets created and seeded everytime the function is called
    std::uniform_int_distribution card{1, 52};
    return card(mt);
}

int main()
{
    std::cout << getCard();
    return 0;
}   // might not be random at all