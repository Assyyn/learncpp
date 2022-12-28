// When you instantiate a new object, the object’s constructor is called
// implicitly. It’s not uncommon to have a class with multiple constructors that
// have overlapping functionality. Consider the following class:
class Foo
{
public:
    Foo()
    {
        // code to do A
    }

    Foo(int value)
    {
        // code to do A
        // code to do B
    }
};

// This class has two constructors: a default constructor, and a constructor
// that takes an integer. Because the “code to do A” portion of the constructor
// is required by both constructors, the code is duplicated in each constructor.

// This provides an example of constructors with overlapping functionality