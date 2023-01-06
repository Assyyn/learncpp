#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Student.h"

#include <functional> // for std::reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Classroom
{
public:
    // using a reference wrapper to store the `Student`s in a std::vector
    //(by reference, hence the name)
    using students = std::vector<std::reference_wrapper<const Student>>;
    // why use references? to avoid unnecessary copying of `Student` objects
    // Instead of references, we could use pointers, but that would open the
    // possibility to store or pass null pointers.
    // why a wrapper?
    // fixed arrays and the various standard library lists can’t hold references
    // (because list elements must be assignable, and references can’t be
    // reassigned).

private:
    students m_students;

public:
    Classroom() = default;

    void add(const Student& student) { m_students.push_back(student); }
    friend std::ostream& operator<<(std::ostream& os, const Classroom& c);
};

std::ostream& operator<<(std::ostream& os, const Classroom& c)
{
    os << "Students in classroom:\n";
    for (int count{1}; const auto& student : c.m_students)
    {
        os << '#' << count++ << ": " << student.get() << '\n';
    }
    return os;
}

#endif