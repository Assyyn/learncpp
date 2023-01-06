// Showcasing dependencies
// 01/06/023

// A dependency occurs when one object invokes another object’s functionality in
// order to accomplish some specific task. This is a weaker relationship than an
// association, but still, any change to object being depended upon may break
// functionality in the (dependent) caller. A dependency is always a
// unidirectional relationship.

#include <iostream>

class Something
{
private:
    int m_value{};

public:
    Something(int value = 0) : m_value{value} {}

    // std::ostream is a dependency of Something because it uses it in order to
    // accomplish the task of printing to the console, but not otherwise(as in
    // it is not directly related to std::ostream)
    friend std::ostream& operator<<(std::ostream& os, const Something& s)
    {
        os << s.m_value;
        return os;
    }
};