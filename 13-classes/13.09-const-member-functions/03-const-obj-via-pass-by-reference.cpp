#include <iostream>
#include <string>

// We pass expensive datatypes by const reference all the time, and therefore
// classes should be const friendly
class Student
{
private:
    std::string m_name{};
    int m_rollNo{};

public:
    Student(std::string name = "*Redacted*", int rollNo = -1) :
        m_name{name}, m_rollNo{rollNo}
    {}

    void print() const
    {
        std::cout << "Name: " << m_name << "\nRoll no: " << m_rollNo << '\n';
    }

    int getRollNo() const
    {
        return m_rollNo;
    }

    // we cannot return a non-const reference here because that would violate
    // const-ness

    // std::string& getName() const{}  \\\ invalid
    const std::string& getName() const
    {
        return m_name;
    }
};

// note that they work because they are const friendly
void doSomething(const Student& student)
{
    student.print();
    student.getName();
    student.getRollNo();
}

int main()
{
    // note to self: passing by const reference allows us to pass in rvalues to
    // functions as well
    doSomething({"Jas", 10}); // sidenote: we just passed in a temporary object
                              // created from the constructor's arguments

    doSomething({"Jim"});

    return 0;
}