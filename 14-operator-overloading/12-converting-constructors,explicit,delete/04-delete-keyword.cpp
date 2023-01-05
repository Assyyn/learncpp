// A better way to resolve the issue is to use the “delete” keyword to delete
// the function:
// Note that the copy constructor and overloaded operators may also be deleted
// in order to prevent those functions from being used.

#include <iostream>
#include <string>

class MyString
{
private:
    std::string m_string{};

public:
    // any use of this constructor is an error
    MyString(char) = delete;

    // allocate string of size x
    explicit MyString(int x) { m_string.resize(x); }

    // allocate string to hold string value
    MyString(const char* string) : m_string{string} {}

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.m_string;
    return os;
}

int main()
{
    MyString mine('x'); // compile error, since MyString(char) is deleted
    std::cout << mine;
    return 0;
}
