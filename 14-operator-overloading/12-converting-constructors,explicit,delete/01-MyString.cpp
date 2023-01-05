#include <iostream>
#include <string>

// we really want to disallow something like this from happening:
class MyString
{
private:
    std::string m_string{};

public:
    // allocate string of size x
    MyString(int x) { m_string.resize(x); }

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
    // this happens because a char is an integral type
    MyString mine = 'x';       // compiles fine, uses MyString(int)
    std::cout << mine << '\n'; // prints new line, because 'mine' is empty

    printString('X'); // compiles fine, uses MyString(int)

    return 0;
}