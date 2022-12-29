// A const member function is a member function that guarantees it will not
// modify the object or call any non-const member functions (as they may modify
// the object).

// consider why the following program wont compile

class Simple
{
private:
    int m_value{};

public:
    Simple() = default;

    int getValue()
    {
        return m_value;
    }
};

int main()
{
    // const Simple object
    const Simple x{};
    x.getValue(); // incompatible?
}

// the answer is because the compiler doesn't know if the member function
// getValue changes the object, which in this case would really be illegal as x
// is const. This is why we need to explicitly make non-modifying functions
// const.