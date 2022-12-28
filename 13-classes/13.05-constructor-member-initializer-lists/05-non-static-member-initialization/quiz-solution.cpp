#include <iostream>
#include <string>
#include <string_view>

// clean up Ball->BallV2, using member initialization lists and
// static-member-initialization
class Ball
{
private:
    std::string m_color;
    double m_radius;

public:
    // Default constructor with no parameters
    Ball()
    {
        m_color = "black";
        m_radius = 10.0;
    }

    // Constructor with only color parameter (radius will use default value)
    Ball(std::string_view color)
    {
        m_color = color;
        m_radius = 10.0;
    }

    // Constructor with only radius parameter (color will use default value)
    Ball(double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    // Constructor with both color and radius parameters
    Ball(std::string_view color, double radius)
    {
        m_color = color;
        m_radius = radius;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

class BallV2
{
private:
    std::string m_color{"black"};
    double m_radius{10.0};

public:
    // Default constructor with no parameters
    BallV2() = default;

    // Constructor with only color parameter (radius will use default value)
    BallV2(std::string_view color) : m_color{color} {}

    // Constructor with only radius parameter (color will use default value)
    BallV2(double radius) : m_radius{radius} {}

    // Constructor with both color and radius parameters
    BallV2(std::string_view color, double radius) :
        m_color{color}, m_radius{radius}
    {}

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    BallV2 def;
    def.print();

    BallV2 blue{"blue"};
    blue.print();

    BallV2 twenty{20.0};
    twenty.print();

    BallV2 blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}