#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name;
    char grade{};
};

// make a simple map class called GradeMap that holds a vector of StudentGrade
// overload operator[] to allow for searching by key and assignment
class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](const std::string& name)
    {
        auto found{
            std::find_if(m_map.begin(), m_map.end(), [&](const auto& student) {
                return student.name == name;
            })};

        if (found != m_map.end())
            return found->grade;

        m_map.push_back({std::string{name}});

        return m_map.back().grade;
    }
};

int main()
{
    GradeMap grades{};

    char& gradeJoe{grades["Joe"]}; // does a push_back
    gradeJoe = 'A';

    char& gradeFrank{grades["Frank"]}; // does a push_back
    gradeFrank = 'B';

    // search by key
    std::cout << "Joe has a grade of " << gradeJoe << '\n';
    std::cout << "Frank has a grade of " << gradeFrank << '\n';

    return 0;
}