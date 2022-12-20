#include <array>
#include <iostream>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{
    std::array<House, 3> houses{}; // array of struct House

    houses[0] = {13, 4, 30};
    houses[1] = {14, 3, 10};
    houses[2] = {15, 2, 30};

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number << " has "
                  << (house.stories * house.roomsPerStory) << " rooms.\n";
    }

    // You cannot initialize the array of structs like this
    // std::array<House, 3> hostels{
    //     {}, {}, {}}; // this is because a std::array is defined as a struct
    //     that
    //                  // contains a C-style array member. The compiler will
    //                  // initialize the underlying C-style array only

    // How to?:
    std::array<House, 3> hostels{
        {{}, {}, {}}}; // the added brace makes it clear that the 3 inner
                       // elements are elements of the array

    return 0;
}