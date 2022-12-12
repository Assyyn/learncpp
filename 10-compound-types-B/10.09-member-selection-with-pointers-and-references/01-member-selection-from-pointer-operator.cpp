#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee hashish{1, 24, 40000};

    Employee* ptr{&hashish};

    std::cout << (*ptr).id
              << '\n'; // ugly, but works. Access the underlying
                       // object through dereference first, then accessing id
    std::cout << ptr->id << '\n'; // using the '->' operator to access id

    return 0;
}

// prefer -> when accessing struct members through pointers