#include <iostream>
#include <string>

// thing to note is that we can use program-defined types
// as members of other such types, because they are now technically
// 'types'. And structs are just a collection of related types to
// represent something

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Company
{
    int numberOfEmployees{};
    Employee CEO{}; // Employee is a struct within the Company struct
};

// we can also nest struct definitions inside other structs:
struct Classroom
{
    struct Student // accessed via Classroom::Student
    {
        std::string name;
        int age{};
        int rollNumber{};
    };

    int numberOfStudents{};
    Student ClassRep{}; // Student is a struct within the Classroom struct
};

int main()
{
    // nested initialization list to initialize Employee
    Company myCompany{7, {1, 32, 55000.0}};
    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage

    Classroom myClassroom{40, {"Barry Allen", 14, 14}};
    std::cout << myClassroom.ClassRep.name << '\n';

    return 0;
}