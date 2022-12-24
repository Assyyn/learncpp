#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array arr{1, 9, -1, 3, 35};

    // let's try and track the number of comparisions made by std::sort while
    // sorting this array
    int comparisions{0};

    std::sort(arr.begin(), arr.end(), [&comparisions](int x, int y) {
        ++comparisions;
        return x > y; // sort in descending order
    });

    // the value of @comparisions was changed and retained in the original
    // object because we captured it by reference!
    std::cout << "Comparisions: " << comparisions << '\n';

    return 0;
}