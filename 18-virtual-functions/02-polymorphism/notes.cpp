#include <string>

// An abstract class to derive Book-related classes from
// Abstract classes are ones that have pure virtual functions
class Book_Abstract
{
protected:
    std::string m_name;
    long m_id;

public:
    // pure virtual function: marked by special syntax(=0).
    virtual std::string getName() const = 0;
};

// another way of making a class *only* derivable from: make its destructor
// protected. Example:
class Inheritable
{
protected:
    // only classes derived from this class can access the destructor, and can
    // use it to perform proper destruction
    ~Inheritable() = default;

public:
    void doSomething() const
    {
        // something
    }
};

class Inherited : public Inheritable
{
private:
    int* m_array{};

public:
    ~Inherited()
    {
        delete[] m_array;            // first free allocated memory
        Inheritable::~Inheritable(); // call the base destructor to do
                                     // generic stuff
    }
};

// virtual destructors
class vBase
{
public:
    virtual ~vBase() {
    } // does not have to be protected anymore because inherited class can
      // override it to get desired destructor calls

    void doSomething() const {}
};

class vDerived : public vBase
{
private:
    int* m_array;

public:
    ~vDerived() override
    {
        delete[] m_array;
        vBase::~vBase();
    }
};

int main()
{
    // Book_Abstract{}; // cannot make object of abstract class
    // Inheritable{};   // destructor is inaccessible from public
    Inherited p{}; // fine, destructor is public

    Inheritable* inhtbl{&p};
    delete inhtbl; // cannot call destructor: protected
                   // would have called ~Inheritable if our destructor was
                   // public, memory leaked!

    vDerived* vd{new vDerived};
    vBase* vb{vd};
    delete vb; // calls vDerived::~vDerived(), no memory leaks!
}