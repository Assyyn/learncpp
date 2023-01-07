// A generic Student which derives from the Person class
// because a Student 'is-a' Person

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h" // class from which we will derive

#include <iostream>
#include <string_view>

class Student : public Person
{
private: // it does have m_name and m_age, but they are not accessible because
         // they are `private`
    int m_rollNo{};

public:
    Student(std::string_view name = "", int age = 0, int rollNo = 0) :
        Person(name, age), m_rollNo{rollNo}
    // it also inherits `Person`'s constructor, to which we can also delegate
    // work
    {}

    // getter(also inherited getAge() and getName()), we donot have to redefine
    // or redeclare any of the inherited members.
    int getRollNo() const { return m_rollNo; }

    // setter
    void setRollNo(int newRollNo) { m_rollNo = newRollNo; }
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Name: " << student.getName() << ',' << "Age: " << student.getAge()
       << ',' << "Roll No: " << student.getRollNo() << '.';

    return os;
}

#endif