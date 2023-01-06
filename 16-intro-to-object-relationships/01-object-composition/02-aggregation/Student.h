#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <string_view>

class Student
{
private:
    std::string m_name;
    int m_rollNo;

public:
    Student(std::string_view name = "*insert name here*", int rollNo = -1) :
        m_name{name}, m_rollNo{rollNo}
    {}

    std::string_view name() const { return m_name; }
    int rollNo() const { return m_rollNo; }
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Name: " << student.name() << ", Roll No: " << student.rollNo();
    return os;
}

#endif