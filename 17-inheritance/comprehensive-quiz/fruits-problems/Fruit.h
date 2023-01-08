#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string_view name, std::string_view color) :
        m_name{name}, m_color{color}
    {}

    std::string_view getName() const { return m_name; }
    std::string_view getColor() const { return m_color; }
};

#endif