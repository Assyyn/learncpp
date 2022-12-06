// lvalues expressions are those that evaluate to variables or other identifiable objects that persist beyond the end of the expression.
// rvalues expressions are those that evaluate to literals or the returned value of functions and operators that are discarded at the end of the expression.

#include <iostream>

int return5()
{
    return 5;
}

int main()
{
    int x{9}; // 9 is an rvalue expression
    int y{x}; // x is an lvalue expression, as it evaluates to variable x (which has an identifier)
              // -> it is also a modifiable lvalue expression, as it's value can be modified

    const double d{1.4}; // 1.4 is an rvalue expression
    double e{d};         // d is a non-modifiable lvalue expression as it's a constant
    int z{return5()};    // return 5 is an rvalue expression (since the result is returned by value)

    int w{x + 1};               // x+1 is an rvalue expression
    int q{static_cast<int>(d)}; // the result of static casting d to int is an rvalue expression

    // assignment operator requires a format such as: (modifiable)lvalue = rvalue
    // so 5 = x; fails because it does not meet the criteria, but x = 5; is perfectly fine
    // but then the following should be an error, right? ...
    x = x + 1; // here, 'x' on the left side of the assignment is an lvalue expression that evaluated to variable x.
    // in the right side of the assignment, x is implicitly converted to an rvalue where now it's value is used.(here,9)
    // the statement resolves to: x = 9 + 1; which matches our requirement

    return 0;
}

// lvalue expressions evaluate to identifiable objects or functions
// return5(), x+1, static_cast<int>(d) are rvalue expressions because they produce temporary values that are not identifiable objects
// identifiable objects can be differentiated from other similar entities (typically by comparing the address of the entity)