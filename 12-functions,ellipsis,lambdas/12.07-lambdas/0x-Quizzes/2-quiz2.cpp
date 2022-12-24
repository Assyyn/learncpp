#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// use std::sort and a lambda to sort the seasons by their average temperatures

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{{{"Spring", 285.0},
                                   {"Summer", 296.0},
                                   {"Fall", 288.0},
                                   {"Winter", 263.0}}};

    // sort by Ascending Average Temperature
    auto byAvgTemp{[](const Season& A, const Season& B) {
        return A.averageTemperature < B.averageTemperature;
    }};

    std::sort(seasons.begin(), seasons.end(), byAvgTemp);

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}