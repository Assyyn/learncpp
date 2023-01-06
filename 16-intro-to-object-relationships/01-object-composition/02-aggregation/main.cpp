#include "Classroom.h"
#include "Student.h"

#include <iostream>

int main()
{
    Student s1{"Jack", 24};
    Student s2{"Hima", 13};
    Student s3{"Loria", 13};
    {
        Classroom grade_9C{};
        grade_9C.add(s1);
        grade_9C.add(s2);
        grade_9C.add(s3);

        std::cout << grade_9C << '\n';
    }

    std::cout << s1 << " exists!\n";
    std::cout << s2 << " exists!\n";
    std::cout << s3 << " exists!\n";

    return 0;
}