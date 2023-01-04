#ifndef MYSTRING_H
#define MYSTRING_H

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(std::string_view str = {}) : m_string{str} {}

    friend std::ostream& operator<<(std::ostream& os, const MyString& s);

    MyString operator()(int start, int length) const;

    std::string_view substr(int start, int length) const;
};

std::ostream& operator<<(std::ostream& os, const MyString& s)
{
    os << s.m_string;
    return os;
}

MyString MyString::operator()(int start, int length) const
{
    assert(start >= 0);
    assert(start + length <= static_cast<int>(m_string.length()) &&
           "MyString::operator()(int,int): SubString is out of range");

    return {m_string.substr(start, length)};
}

std::string_view MyString::substr(int start, int length) const
{
    assert(start >= 0);
    assert(start + length <= static_cast<int>(m_string.length()) &&
           "MyString::substr(int,int): SubString is out of range");

    return std::string_view{m_string.begin() + start,
                            m_string.begin() + start + length};
}

#endif