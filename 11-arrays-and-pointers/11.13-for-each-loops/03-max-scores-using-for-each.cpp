#include <iostream>

int main()
{
    constexpr int scores[]{90, 84, 39, 91, 43, 55};
    int maxScore{0};

    // we use auto here because copying an int is trivial
    for (auto score : scores)
    {
        if (score > maxScore)
            maxScore = score;
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}