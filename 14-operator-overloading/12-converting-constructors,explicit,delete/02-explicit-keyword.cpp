#include <iostream>

// Lets take the same MyString class and use the explicit keyword to disallow
// such implicit conversions
class MyString
{
private:
    std::string m_string{};

public:
    // allocate string of size x, take an int(and nothing else)
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
    MyString mine = 'x'; // compile error, since MyString(int) is now explicit
                         // and nothing will match this
    std::cout << mine;

    printString('x'); // compile error, since MyString(int) can't be used for
                      // implicit conversions

    // only prevents implicit conversions, the following would be valid:
    std::cout << static_cast<MyString>(5) << '\n';

    // uniform initialization will also still convert parameters to match
    MyString mind{'m'};

    return 0;
}
