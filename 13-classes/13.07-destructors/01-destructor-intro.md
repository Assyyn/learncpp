# Destructors

A destructor is another special kind of class member function that is
executed when an object of that class is destroyed. Whereas constructors are
designed to initialize a class, destructors are designed to help clean up.

When an object goes out of scope normally, or a dynamically allocated object is
explicitly deleted using the delete keyword, the class destructor is
automatically called (if it exists) to do any necessary clean up before the
object is removed from memory. For simple classes (those that just initialize
the values of normal member variables), a destructor is not needed because C++
will automatically clean up the memory for you.

However, if your class object is holding any resources (e.g. dynamic memory, or
a file or database handle), or if you need to do any kind of maintenance before
the object is destroyed, the destructor is the perfect place to do so, as it is
typically the last thing to happen before the object is destroyed.

## Destructor Naming

Like constructors, destructors have specific naming rules:

- The destructor must have the same name as the class, preceded by a tilde (~).
- The destructor can not take arguments.
- The destructor has no return type.
- A class can only have a single destructor.

Generally you should not call a destructor explicitly (as it will be called automatically when the object is destroyed), since there are rarely cases where you’d want to clean up an object more than once. However, destructors may safely call other member functions since the object isn’t destroyed until after the destructor executes.

---

### Source: *[learncpp](https://www.learncpp.com/cpp-tutorial/destructors/)*
