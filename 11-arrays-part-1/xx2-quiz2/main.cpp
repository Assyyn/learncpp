/* Question #2

Write the following program: Create a struct that holds a student’s first name
and grade (on a scale of 0-100). Ask the user how many students they want to
enter. Create a std::vector to hold all of the students. Then prompt the user
for each name and grade. Once the user has entered all the names and grade
pairs, sort the list by grade (highest first). Then print all the names and
grades in sorted order.
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <ranges>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    std::size_t grade{};
};

int getNumber()
{
    while (true)
    {
        std::cout << "How many students do you have in your classroom?: ";

        int temp{};
        std::cin >> temp;

        if (temp <= 0)
        {
            continue;
        }

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        return temp;
    }
}

Student getScore()
{
    Student res;

    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, res.name);

    std::cout << "Enter score: ";
    std::cin >> res.grade;

    return res;
}

std::vector<Student> getStudents()
{
    using Students = std::vector<Student>;

    int numStudents{getNumber()};

    Students students(static_cast<Students::size_type>(numStudents));

    for (int currentIndex{0}; auto& student : students)
    {
        students[currentIndex] = std::move(getScore());
        currentIndex++;
    }

    return students;
}

bool greater(Student& A, Student& B)
{
    // sort student in ascending order wrt their grades
    return (A.grade > B.grade);
}

int main()
{
    auto scores{std::move(getStudents())};

    std::ranges::sort(scores, greater);

    for (const auto& student : scores)
    {
        std::cout << student.name << " got a grade of " << student.grade
                  << '\n';
    }
}