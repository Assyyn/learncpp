// Base class #2 : An Employee

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_employer;
    double m_wage{};

public:
    Employee(std::string_view employer, double wage) :
        m_employer{employer}, m_wage{wage}
    {}

    std::string_view getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

#endif