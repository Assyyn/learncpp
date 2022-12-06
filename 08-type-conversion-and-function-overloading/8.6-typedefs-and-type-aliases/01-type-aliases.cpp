#include <iostream>
#include <typeinfo>

int main()
{
    using Distance = double; // define Distance as an alias for type double
    using Speed = double;    // define Speed as an alias for type double

    Distance kmToDestination{1000}; // defines a variable of type double (as Distance is an alias)
    Speed ofCar{kmToDestination};   // semantic error, speed is not the same as distance(we defined them like so, as aliases for 'double')
                                    // therefore, type aliases not type safe

    std::cout << typeid(kmToDestination).name() << ": " << kmToDestination << '\n'; // d: 1000

    return 0;
}

// name your Type aliases like Classes, starting with a capital letter and using no suffix