#include <iostream>

enum class Animals
{
    chicken,
    dog,
    cat,
    elephant,
    snake,
    duck,

    maxAnimals,
};

// Overload the unary + operator to convert Animals to the underlying type
constexpr auto operator+(Animals a) noexcept
{
    return static_cast<std::underlying_type_t<Animals>>(a);
}

int main()
{
    std::cout << +Animals::chicken << '\n'; // prints 0
    // convert Animals::chicken to integer using unary operator+

    // ha.ha. (you can still try silly things)
    std::cout << "(duck+snake)";
    (+Animals::duck + (+Animals::snake) > (+Animals::maxAnimals))
        ? (printf(">(maxAnimals)"))
        : (printf("<(maxAnimals)"));

    return 0;
}