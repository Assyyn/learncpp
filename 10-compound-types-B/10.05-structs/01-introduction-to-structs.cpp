#include <iostream>

// defining a struct:
struct Employee
{
    // everything declared inside a struct is a member(variable,function,or
    // type)
    int id{};
    int age{};
    double wage{};
};

int main()
{
    // creating instances/objects of type Employee:
    Employee harry; // variable harry of type Employee

    // accessing struct members(using operator.)
    harry.age;
    harry.id;
    harry.wage;

    // doing something with struct members

    // assignment
    harry.age = 35;
    harry.id = 174421;
    harry.wage = 3000;

    // other operations
    std::cout << harry.age << '\n';
    harry.wage += 100; // increase harry's salary, promotion
    ++harry.age;       // today is also harry's birthday

    // consistency and ease of use
    Employee maria;

    // assignment
    maria.age = 32;
    maria.id = 174419;
    maria.wage = 5000;
    // maira and harry have the same member names, but they are clearly
    // different, providing consistency and organisation to our code

    if (maria.wage > harry.wage)
    {
        std::cout << "Maria makes " << maria.wage - harry.wage
                  << " more than Harry\n";
    }
    else if (maria.wage < harry.wage)
    {
        std::cout << "Harry makes " << harry.wage - maria.wage
                  << " more than Maria\n";
    }
    else
    {
        std::cout << "Both Harry and Maria make the same amount of money\n";
    }
}