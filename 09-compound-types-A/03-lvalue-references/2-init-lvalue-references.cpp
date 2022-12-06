#include <iostream>

// ALL references MUST be initialized
// lvalue references must be bound to a modifiable value

int main()
{
    // int &invalidRef; // error: references must be initialized

    int x{5};
    int &ref{x}; // okay: reference to an int is bound to int variable

    const double d{3};
    // int &invalidRef2{d}; //invalid: can't bind to non-modifiable lvalue
    const double &refX{d}; // can only bind to const lvalues when reference itself is const
                          // and must match type in most cases

    double &ref2{x}; // error: can't bind to int variable
    // lvalue references to 'void' are disallowed
}

// When a reference is initialized with an object (or function), we say it is bound to that object (or function).
// The process by which such a reference is bound is called reference binding.
// The object (or function) being referenced is sometimes called the referent.