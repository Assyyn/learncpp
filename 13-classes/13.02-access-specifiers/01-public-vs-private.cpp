// Consider the following identical definitions for a struct and a class:
struct A
{
    // struct members are public by default
    int m_member{};

    // we can also have private member variables in structs
  private:
    int m_private{};
};

// it turns out that by default, members of a class are private(inaccessible
// from outside the class)
class B
{
    int m_member{}; // m_member is private

    // we can make class members public by using the public: keyword
  public:
    int m_public{};
};

// now consider accessing these member variables outside of the class
int main()
{
    A x;
    x.m_member = 10; // fine

    B y;
    y.m_public = 20; // fine
    y.m_member = 20; // compiler error, explained line 12

    return 0;
}

// Access specifiers determine who has access to the members that follow the
// specifier