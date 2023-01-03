#include <cassert>
#include <iostream>
#include <iterator>

// a trivial class with an array as a member variable
class IntList
{
private:
    int m_array[10]{};

public:
    int&
        operator[](int index) // return by reference so it is valid as an lvalue
    {
        // allows to error-check index before trying to access
        assert(index >= 0 && index < std::size(m_array) &&
               "Range-access error.");
        return m_array[index];
    }

    int operator[](int index) const
    {
        assert(index >= 0 && index < std::size(m_array) &&
               "Range-access error.");
        return m_array[index];
    }
};

int main()
{
    IntList list{};
    list[5] = 10;
    std::cout << list[5] << '\n';

    IntList* x{new IntList{}};
    // x[2] = 3; // UB if we could assign integers to an array of IntList's
    // else won't compile

    (*x)[2] = -1;                 // assign to x[0]'s IntList[2]
    std::cout << x[0][2] << '\n'; // error prone if used like this
    std::cout << (*x)[2] << '\n'; // this is clearer and less error prone
    delete x;                     // it is not recommended to do this

    // list[10]; // error: range-access error
    // assignment through subscripting is invalid for const objects
    const IntList list2{};
    // list2[9] = 9; // error: cannot assign to rvalue
    // std::cout << list2[9] << '\n';

    return 0;
}