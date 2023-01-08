#include "Employee.h"
#include "Person.h"
#include "Teacher.h"

#include <iostream>

int main()
{
    // A teacher is-a Person and is-a(n) Employee:
    Teacher haepz{"Haepsz", 30, "Aluminati College", 16.02, 12};

    // member functions of Person and Employee classes, for demonstration(use
    // without T:: ) that Teacher really inherited from multiple classes.
    std::cout << haepz.Person::getName() << ", " << haepz.Person::getAge()
              << '\n';
    std::cout << haepz.Employee::getEmployer() << ", "
              << haepz.Employee::getWage() << '\n';

    return 0;
}