#include <iostream>
#include <random>
#include <limits>

namespace Random // for random number
{
    std::random_device rd;

    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::mt19937 mt{ss};

    int get(int min, int max)
    {
        std::uniform_int_distribution die{min, max};
        return die(mt);
    }
}

void ignoreLine() // ignore everything upto the first \n
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getT()
{
    while (true)
    {
        T x{};
        if (std::cin >> x) // if everything's fine, proceed normally
        {
            ignoreLine();
            return x;
        }

        // we reach here if the previous operation has failed, let's handle it
        std::cin.clear();
        ignoreLine();
        std::cout << "Not a " << typeid(x).name() << ". Please, try again.\n"; // typeid(variable).name : returns name of type of variable
    }
};

int getGuess(int attemptNo)
{
    while (true)
    {
        std::cout << "Guess #" << attemptNo << ": ";
        int x{};
        if (std::cin >> x) // if everything's fine, proceed normally
        {
            if (x < 1 || x > 100)   // if x out-of-bounds
            {
                ignoreLine();
                continue;
            }
            ignoreLine();
            return x;
        }

        // we reach here if the previous operation has failed, let's handle it
        std::cin.clear();
        ignoreLine();
    }
}

bool playGame(int maxAttempts,int answer)
{
    int attempts{1};
    while (attempts <= maxAttempts)
    {
        int guess{getGuess(attempts)};
        if (guess < answer)
            std::cout << "Your answer is too low.\n";
        else if (guess > answer)
            std::cout << "Your answer is too high.\n";
        else // guess == answer
            return true;

        attempts++;
    }
    // max attempts reached and guess!=answer, return false
    return false;
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to try again (y/n)? ";
        char ch{getT<char>()};

        switch(ch)
        {
            case 'y': case 'Y': return true;
            case 'n': case 'N': return false;
        }
    }
}

int main()
{
    bool gameOn{true};
    constexpr int maxAttempts {7};
    while (gameOn)
    {
        int answer{Random::get(1, 100)};
        bool won {playGame(maxAttempts,answer)};
        if (won)
            std::cout << "Congrats! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct answer was: " << answer << '\n';
        gameOn = playAgain();
    }
}
