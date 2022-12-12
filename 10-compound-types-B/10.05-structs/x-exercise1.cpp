/* You are running a website, and you are trying to keep track of how much money
 * you make per day from advertising.
 * Declare an advertising struct that keeps track of how many ads you’ve shown
 * to readers, what percentage of ads were clicked on by users, and how much you
 * earned on average from each ad that was clicked.
 * Read in values for each of these fields from the user.
 * Pass the advertising struct to a function that prints each of the values,
 * and then calculates how much you made for that day (multiply all 3 fields
 * together)*/

#include <iostream>

struct Advertising
{
    int adsShown{0};
    double clickThroughRatePercentage{0};
    double averageEarningsPerClick{0};
};

Advertising getAdvertising()
{
    Advertising x;

    std::cout << "How many ads were shown today?  ";
    std::cin >> x.adsShown;

    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> x.clickThroughRatePercentage;

    std::cout << "What was the average earnings per click? ";
    std::cin >> x.averageEarningsPerClick;

    return x;
}

void printAdvertising(const Advertising& x)
{
    std::cout << "Number of ads shown:" << x.adsShown << '\n';
    std::cout << "Click through rate: " << x.clickThroughRatePercentage << '\n';
    std::cout << "Average earnings per click: " << x.averageEarningsPerClick
              << '\n';
    std::cout << "Total money made today: $"
              << x.averageEarningsPerClick * x.adsShown *
                     x.clickThroughRatePercentage
              << '\n';
}

int main()
{
    Advertising noodles{getAdvertising()};
    printAdvertising(noodles);
    return 0;
}