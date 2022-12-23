#include <iostream>
#include <string_view>

// for-each loops do not provide a direct way to get the index of the current
// element(because many of the structures that for-each supports are not
// directly indexable).

int main()
{
    constexpr std::string_view names[]{"Alex", "Betty", "Caroline",
                                       "Dave"}; // Names of the students

    constexpr int scores[]{84, 92, 76, 81}; // their scores
    int maxScore{0};

    // Before C++20, we would need to do something like this:
    int index{0};
    for (auto score : scores)
    {
        if (score > maxScore)
        {
            // do something
        }
        ++index;
    }

    // Since C++20, we can do the following to keep track of our indexes:
    for (int i{0}; auto score : scores) // i is the index of the current element
    {
        if (score > maxScore)
        {
            std::cout << names[i] << " beat the previous best score of "
                      << maxScore << " by " << (score - maxScore)
                      << " points!\n";
            maxScore = score;
        }

        ++i;
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}