#include <algorithm>
#include <iostream>
#include <string>

int getNameCount()
{
    std::cout << "How many names do you wish to enter?: ";
    int numNames{};
    std::cin >> numNames;
    return numNames;
}

void getNames(std::string* namesList, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, namesList[i]);
    }
}

void printNames(std::string* namesList, int length)
{
    std::cout << "\nHere is your sorted list:\n";
    for (int i = 0; i < length; ++i)
    {
        std::cout << "Name #" << i + 1 << ": " << namesList[i] << '\n';
    }
}

int main()
{
    int length{getNameCount()};

    auto* namesList{new (std::nothrow) std::string[length]{}};

    getNames(namesList, length);

    std::sort(namesList, namesList + length);

    printNames(namesList, length);

    delete[] namesList;
    namesList = nullptr;

    return 0;
}