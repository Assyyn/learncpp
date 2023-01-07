// A generic Person class from which other classes can be derived

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name{}; // every person has a name
    int m_age{};          // and an age
public:
    Person(std::string_view name = "", int age = 0) : m_name{name}, m_age{age}
    {}

    // getters
    std::string_view getName() const { return m_name; }
    int getAge() const { return m_age; }

    // setters
    void setName(std::string_view newName) { m_name = newName; }
    void setAge(int newAge) { m_age = newAge; }
};

#endif
