// Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program
// asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program
// should be able to identify the number after asking no more than seven questions

#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore input until whitespace
}

bool lessThanMean(int mean) // separate to two functions, one for character input handling and another to return if less than mean : incomplete
{
    char response{};
    while (true)
    {
        std::cout << "Is the number you are thinking of less than " << mean << "? ";
        std::cin >> response;

        switch (response)
        {
        case 'y':
        case 'Y':
            ignoreLine();
            return true;
        case 'n':
        case 'N':
            ignoreLine();
            return false;
        }

        if (!std::cin) // stream went bad
        {
            std::cin.clear(std::ios_base::badbit);
            throw std::runtime_error("Unexpected input. Terminating...");
        }

        // stream failed
        std::cin.clear();
        ignoreLine();
    }
}

int found(int &low, int &high) // returns value if deduced; 0 if not
{
    int mean{(low + high) / 2};
    if (lessThanMean(mean))
    {
        high = mean;
        int diff{high - low};
        if (diff == 1)
        {
            return low;
        }
    }
    else
    {
        low = mean;
        int diff{high - low};
        if (diff == 1)
        {
            return high;
        }
    }
    return 0; // exact value not found
}

int playGame(int low, int high)
{
    for (int count{1}; count <= 7; ++count)
    {
        int answer{found(low, high)};
        if (answer)
            return answer;
    }
}

int main()
{
    constexpr int low{1};
    constexpr int high{100};

    playGame(low, high);

    return 0;
}
