// In our MyString case, we really want to completely disallow ‘x’ from being
// converted to a MyString (whether implicit or explicit, since the results
// aren’t going to be intuitive). One way to partially do this is to add a
// MyString(char) constructor, and make it private:
#include <iostream>
#include <string>

class MyString
{
private:
    std::string m_string{};

    MyString(char) {} // objects of type MyString(int) can't be constructed from
                      // outside the class

public:
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

void printString(const MyString& str) { std::cout << str; }

int main()
{
    MyString mine('x'); // compile error, since MyString(char) is private
    std::cout << mine;
    return 0;
}