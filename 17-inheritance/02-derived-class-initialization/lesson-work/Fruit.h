// A generic, minimal fruit class

#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    using sv = std::string_view;

    Fruit(sv name = "", sv color = "") : m_name{name}, m_color{color} {}

    // getters
    sv getName() const { return m_name; }
    sv getColor() const { return m_color; }

    // setters
    void setName(sv newName) { m_name = newName; }
    void setColor(sv newColor) { m_color = newColor; }
};

#endif