#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int scores[]{49, 71, 31, 90, 66};
    constexpr int numStudents{static_cast<int>(std::size(scores))};

    int totalScore{0};
    int maxScore{0};

    for (int student{0}; student < numStudents; ++student)
    {
        totalScore += scores[student];
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
        }
    }

    auto averageScore{static_cast<double>(totalScore) / numStudents};

    std::cout << "average score was: " << averageScore << '\n';

    std::cout << "max score was: " << maxScore << '\n';

    return 0;
}