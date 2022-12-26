#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using Numbers = std::vector<int>;

// change this to change game settings
namespace config
{
constexpr int minMultiplier{2};
constexpr int maxMultiplier{4};
constexpr int maxWrongAnswer{4};
} // namespace config

namespace random
{
int getRandomInt(int from, int thru)
{
    std::random_device rd;
    std::seed_seq sq{rd(), rd(), rd(), rd(), rd(), rd()};

    static std::mt19937 mt(sq);

    return std::uniform_int_distribution(from, thru)(mt);
}
} // namespace random

// generates @count numbers starting at @start*@start and multiplies every
// square number by multiplier
Numbers generateSequence(int start, int count, int multiplier)
{
    Numbers sequence(count);

    int n{start};

    for (auto& number : sequence)
    {
        number = (n * n) * multiplier;
        ++n;
    }

    /* alternate fill(not clean) using std::for_each:

    std::for_each(sequence.begin(),sequence.end(),[n,multiplier](int x){
        x = (n*n)*multiplier;
        ++n;
    });

    */

    return sequence;
}

// Asks the user to input start and amount of numbers, then calls
// @generateSequence
Numbers generateUserSequence(int multiplier)
{
    std::cout << "Start where? ";
    int start{};
    std::cin >> start;

    std::cout << "How many? ";
    int count{};
    std::cin >> count;

    return generateSequence(start, count, multiplier);
}

// print Start of game prompt
void printTask(Numbers::size_type count, int multiplier)
{
    std::cout
        << "I generated " << count
        << " square numbers. Do you know what each number is after multiplying it by "
        << multiplier << "?\n";
}

int getGuess()
{
    std::cout << "> ";
    int guess{};
    std::cin >> guess;

    return guess;
}

// true if guess was found in sequence
bool findAndRemove(Numbers& numbers, int guess)
{
    auto found{std::find(numbers.begin(), numbers.end(), guess)};
    if (found == numbers.end())
        return false;

    numbers.erase(found);
    return true;
}

// called when user guesses a number from the sequence
void printSuccess(Numbers::size_type numbersleft)
{
    std::cout << "Nice! ";
    if (numbersleft == 0)
        std::cout << "You found all the numbers!\n";
    else
        std::cout << numbersleft << " number(s) left.\n";
}

// determine the closest number to the incorrect guess of user
int closestNumber(const Numbers& numbers, int guess)
{
    return *std::min_element(numbers.begin(), numbers.end(), [=](int x, int y) {
        return std::abs(x - guess) < std::abs(y - guess);
    });
}

// called when user guesses incorrectly
void printFailure(const Numbers& numbers, int guess)
{
    int closest{closestNumber(numbers, guess)};

    std::cout << guess << " is wrong! ";

    if (std::abs(guess - closest) <= config::maxWrongAnswer)
    {
        std::cout << "Try " << closest << " next time!\n";
    }
}

// Returns false if the game is over, true otherwise
bool playRound(Numbers& numbers)
{
    int guess{getGuess()};

    if (findAndRemove(numbers, guess))
    {
        printSuccess(numbers.size());

        return !numbers.empty();
    }
    else
    {
        printFailure(numbers, guess);
        return false;
    }
}

int main()
{
    int multiplier{
        random::getRandomInt(config::minMultiplier, config::maxMultiplier)};

    Numbers numbers{generateUserSequence(multiplier)};

    printTask(numbers.size(), multiplier);

    while (playRound(numbers))
        ;

    return 0;
}