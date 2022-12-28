#include <iostream>
#include <string>
#include <string_view>

/*  Write a class named Ball. Ball should have two private member variables with
 * default values: m_color (“black”) and m_radius (10.0). Ball should provide
 * constructors to set only m_color, set only m_radius, set both, or set neither
 * value.*/
class Ball
{
private:
    std::string m_color{};
    double m_radius{};

public:
    Ball(std::string_view color = "black", double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
    }

    Ball(double radius)
    {
        m_color = "blue";
        m_radius = radius;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}