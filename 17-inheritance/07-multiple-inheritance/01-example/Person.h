// 1. Base class #1 : A Person

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name;
    int m_age{};

public:
    Person(std::string_view name, int age) : m_name{name}, m_age{age} {}

    std::string_view getName() const { return m_name; }
    int getAge() const { return m_age; }
};

#endif