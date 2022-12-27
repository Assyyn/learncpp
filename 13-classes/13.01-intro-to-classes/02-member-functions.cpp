#include <iostream>

// Classes and structs can also contain functions. Functions defined inside of a
// class are called member functions
// It is recommended that classes be named starting with a capital letter

// An example class
class DateClass
{
  public:
    /* Using the “m_” prefix for member variables helps distinguish member
     * variables from function parameters or local variables inside member
     * functions. This is useful for several reasons. First, when we see an
     * assignment to a variable with the “m_” prefix, we know that we are
     * changing the state of the class instance. Second, unlike function
     * parameters or local variables, which are declared within the function,
     * member variables are declared in the class definition. Consequently, if
     * we want to know how a variable with the “m_” prefix is declared, we know
     * that we should look in the class definition instead of within the
     * function.*/
    int m_year{};
    int m_month{};
    int m_day{};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main()
{
    DateClass date{2022, 12, 27};

    // member selection operator is used to access it's underlying methods and
    // variables
    date.m_day = 7;
    date.print();

    return 0;
}

// a member function can 'see' any other function in the class, so it is
// completely fine to do this
class foo
{
  public:
    void x()
    {
        y();
    } // okay to call y() here, even though y() isn't defined until later in
      // this class
    void y(){};
};