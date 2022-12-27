#include <iostream>
#include <string>

// classes can also have member types or nested types(along with type aliases)
class Student
{
public:
    // type alias(within the class' namespace)
    using IDType = int;

    // member class/struct(typically used by highly advanced
    // programmers)
    class Date
    {
        int m_year{};
        int m_month{};
        int m_day{};
    };

    // member variables
    std::string m_name{};
    IDType m_id{};
    Date m_DOB{};

    // member function
    void print()
    {
        std::cout << "Name: " << m_name << "ID: " << m_id;
    }
};

// more on nested types:
/* Nested types cannot be forward declared. Generally, nested types should only
 * be used when the nested type is used exclusively within that class. Note that
 * since classes are types, it’s possible to nest classes inside other classes
 * -- this is uncommon and is typically only done by advanced programmers.*/