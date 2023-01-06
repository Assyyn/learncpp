// Sometimes objects may have a relationship with other objects of the same
// type. This is called a reflexive association. A good example of a reflexive
// association is the relationship between a university course and its
// prerequisites (which are also university courses).
#include <string>

class Course
{
private:
    std::string m_name;
    const Course* m_prerequisite; // it could have a list of prerequisites too,
                                  // which could be stored in a data structure

public:
    Course(const std::string& name, const Course* prerequisite = nullptr) :
        m_name{name}, m_prerequisite{prerequisite}
    {}
};

int main()
{
    Course course1{"CAMT101"};           // has no prerequisite course
    Course course2{"CACS105", &course1}; // course1 is a prerequisite to course2

    return 0;
}