// Teacher derives from @Employee and @Person publicly
// Multi-level inheritance, then, is a technique which enables a derived class
// to inherit members of multiple(yes, more than two) classes(Parent classes).

#ifndef TEACHER_H
#define TEACHER_H

#include "Employee.h"
#include "Person.h"

class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(std::string_view name, int age, std::string_view employer,
            double wage, int teachesGrade) :
        Person(name, age),
        Employee(employer, wage), m_teachesGrade{teachesGrade}
    {}
};

#endif