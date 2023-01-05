// A trivial string class

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char* m_data{};
    int m_length{};

public:
    // we could also prevent assignments by deleting it:
    // MyString operator=(MyString) = delete;

    MyString(const char* data = nullptr, int length = 0) : m_length{length}
    {
        if (length)
        {
            m_data = new char[length];

            for (int i{0}; i < length; ++i)
            {
                m_data[i] = data[i];
            }
        }
    }

    // copy constructor, needed
    MyString(const MyString& copy) :
        m_data{copy.m_length ? new char[copy.m_length] : nullptr},
        m_length{copy.m_length}
    {
        if (m_length)
        {
            for (int i{0}; i < m_length; ++i)
            {
                m_data[i] = copy.m_data[i];
            }
        }
    }

    // destructor
    ~MyString() { delete[] m_data; }

    // needed to use the copy and swap idiom
    friend void swap(MyString& myStr1, MyString& myStr2);

    // let's use the copy and swap idiom
    MyString& operator=(MyString string);

    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);
};

std::ostream& operator<<(std::ostream& os, const MyString& myStr)
{
    os << myStr.m_data;
    return os;
}

void swap(MyString& myStr1, MyString& myStr2)
{
    // enable ADL
    using std::swap;

    swap(myStr1.m_length, myStr2.m_length);
    swap(myStr1.m_data, myStr2.m_data);
}

// uses the copy constructor to make the copy, swaps it with our MyString object
// there is no need for a self-assignment check; because object is passed by
// value and we don't have to worry about calling delete on the object itself
MyString& MyString::operator=(MyString str)
{
    swap(*this, str);
    // str's destructor gets called here, because it is a temporary copy
    return *this;
}
// On a general note, a remarkably useful guideline is as follows: if you're
// going to make a copy of something in a function, let the compiler do it in
// the parameter list.

#endif