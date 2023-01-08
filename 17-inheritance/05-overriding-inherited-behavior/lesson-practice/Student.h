// A generic Student which derives from the Person class
// because a Student 'is-a' Person
// re-used(and added upon) from 17/01-basic-inheritance-in-c++

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h" // class from which we will derive

#include <iostream>
#include <string_view>

class Student : public Person
{
private: // it does have m_name and m_age, but they are not accessible because
         // they are `private` in the base class
    int m_rollNo{};

public:
    Student(std::string_view name = "", int age = 0, int rollNo = 0) :
        Person(name, age), m_rollNo{rollNo}
    {}

    // getter(also inherited getAge() and getName()), we donot have to redefine
    // or redeclare any of the inherited members.
    int getRollNo() const { return m_rollNo; }

    // setter
    void setRollNo(int newRollNo) { m_rollNo = newRollNo; }
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    // reduce some code redundancy here
    os << static_cast<Person>(student); // to call `Person`'s operator<<
    os << ", RollNo: " << student.getRollNo();

    return os;
}

#endif