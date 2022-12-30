//  Normally we access private members through public member functions. While we
//  could create a normal public member function to access s_value, we’d then
//  need to instantiate an object of the class type to use the function! We can
//  do better. It turns out that we can also make functions static.
#include <iostream>

class Something
{
private:
    static inline int s_value{2};
    char m_char{'x'};

public:
    // static function, can be used without the need for any object to be
    // instantiated(as it belongs to the class itself and not any particular
    // instance)
    static int getValue()
    {
        // static member functions don't point to *this, as they do not work on
        // an object
        return s_value;
    }

    // static member functions can directly access other static members
    // (variables or functions), but not non-static members. This is because
    // non-static members must belong to a class object, and static member
    // functions have no class object to work with! it follows that the
    // following function is
    // illegal :
    static char getChar()
    {
        return m_char; // static functions dont work on objects
    }
};