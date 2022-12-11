#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee ross{1, 45, 30000};

    // you can also aggregate assign to a struct
    ross = {ross.id, 46, 35000}; // ross had a birthday and got a raise

    // using designated initializers for list assignment(c++20):
    ross = {.age = 47, .wage = 40000.20};
    // ross.id gets assigned 0

    std::cout << ross.id << '\n';
    return 0;
}