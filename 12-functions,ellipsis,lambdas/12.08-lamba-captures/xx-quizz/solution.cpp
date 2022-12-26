/* We’re going to write a little game with square numbers (numbers which can be
created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).

Ask the user to input 2 numbers, the first is the square root of the number to
start at, the second is the amount of numbers to generate. Generate a random
integer from 2 to 4, and square numbers in the range that was chosen by the
user. Multiply each square number by the random number. You can assume that the
user enters valid numbers.

The user has to calculate which numbers have been generated. The program checks
if the user guessed correctly and removes the guessed number from the list. If
the user guessed wrong, the game is over and the program prints the number that
was closest to the user’s final guess, but only if the final guess was not off
by more than 4.
*/

// to redo later. too messy

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

namespace random
{
int getRandomNumber(int from, int thru)
{
    std::random_device rd;
    std::seed_seq ssq{rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::uniform_int_distribution range{from, thru};
    static std::mt19937 mt{ssq}; // seed using seeder, only once
    return range(mt);
}
} // namespace random

int getNumber(const std::string_view prompt)
{
    std::cout << prompt;
    int x{};
    std::cin >> x;

    return x;
}

int getGuess()
{
    std::cout << "> ";
    int guess{};
    std::cin >> guess;

    return guess;
}

bool guesses(std::vector<int>& squares)
{
    int guess{getGuess()};

    auto found{std::find(squares.begin(), squares.end(), guess)};
    if (found == squares.end())
    {
        std::cout << guess << " is wrong! ";

        auto closest{
            std::min_element(squares.begin(), squares.end(), [=](int x, int y) {
                return std::abs(x - guess) < std::abs(y - guess);
            })};

        if (std::abs(*closest - guess) <= 4)
            std::cout << "Try " << *closest << " next time!\n";
        return false;
    }

    // else the guess exists in vector, erase it
    squares.erase(found);
    std::cout << "Nice! ";
    if (squares.size() == 0)
    {
        std::cout << "You found all the numbers!\n";
        return true;
    }
    std::cout << squares.size() << " number(s) left.\n";

    return true;
}

void playGame()
{
    // ask for input
    int start{getNumber("Start where? ")};
    int length{getNumber("How many? ")};

    // generate random number
    int randNum{random::getRandomNumber(2, 4)};

    std::vector<int> squares(length);
    // fill the vector by multiplying the range of square numbers with generated
    // random number
    std::for_each(squares.begin(), squares.end(),
                  [start, randNum](int& x) mutable {
                      x = start * start * randNum;
                      start++;
                  });

    std::cout << "I generated " << squares.size() << " square numbers. "
              << "Do you know what each number is after multiplying it by "
              << randNum << "?\n";

    while (guesses(squares))
    {}
}

int main()
{
    playGame();
}