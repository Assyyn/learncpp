// If your class has no constructors, C++ will automatically generate a public
// default constructor for you. This is sometimes called an implicit constructor
class Something
{
private:
    int m_value{};

    // No constructors provided
};

class SomeOtherThing
{
private:
    int m_value{};

public:
    // constructor defined
    SomeOtherThing(int x)
    {
        m_value = x;
    }
};

// we can use =default too
class Nothing
{
private:
    int m_value{};

public:
    Nothing() =
        default; // let the compiler define a default constructor for you

    Nothing(int x)
    {
        m_value = x;
    }
};

int main()
{
    Something
        nothing{}; //--> the default constructor was automatically generated

    SomeOtherThing notReally{}; // --> default constructor not provided

    Nothing{}; // fine

    return 0;
}