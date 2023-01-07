#include "Person.h"
#include "Student.h"

#include <iostream>

void printNameAndAge(const Person& person)
// will also accept a Student parameter, because a
// Student 'is-a' Person
{
    std::cout << person.getName() << ',' << person.getAge() << '\n';
}

int main()
{
    Student jamie("Jamie", 25, 1);
    std::cout << jamie.getName() << '\n'; // inherited function from `Person`

    Person gie("Gie", 34);

    printNameAndAge(jamie); // okay, jamie is-a Person
    printNameAndAge(gie);   // okay

    return 0;
}