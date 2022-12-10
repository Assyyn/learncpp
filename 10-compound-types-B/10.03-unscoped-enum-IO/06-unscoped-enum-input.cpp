#include <iostream>

enum Pet
{
    cat,
    dog,
    turtle,
    monkey,
};

// overloading operator>>
std::istream& operator>>(std::istream& is, Pet& pet)
{
    int input{};
    is >> input;

    pet = static_cast<Pet>(input);
    return is;
}

int main()
{
    // we can either static_cast an integer to an enumerator of the appropriate
    // enumeration:
    std::cout << "Enter a pet (0=cat, 1=dog, 2=turtle, 3=monkey): ";

    int input{};
    std::cin >> input;

    Pet pet{static_cast<Pet>(input)}; // static_cast our integer to a Pet
    std::cout << pet << '\n';         // test

    // or overload operator>> :
    std::cout << "Enter a pet (0=cat, 1=dog, 2=turtle, 3=monkey): ";
    Pet pet2;
    std::cin >> pet2;
    std::cout << pet2 << '\n'; // test

    return 0;
}