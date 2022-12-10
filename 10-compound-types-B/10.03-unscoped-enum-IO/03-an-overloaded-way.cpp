// for convenience, we can just overload 'operator<<' to print an enumerator

#include <iostream>

enum Animal
{
    shark,
    dolphin,
    tiger,
};

// overloading operator<< : (More on it in later chapters)
std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    switch (animal)
    {
        case shark:
            os << "shark";
            break;
        case dolphin:
            os << "dolphin";
            break;
        case tiger:
            os << "tiger";
            break;
        default:
            os << "???";
            break;
    }

    return os;
}
