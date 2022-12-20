#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

int main()
{
    std::array nums{1, 3, 7, 9, 11};

    // the syntax(as i understand it)
    // std::accumulate(beginIter,endIter,initialValue,operation);

    // 0+1+3+7+9+11 = 31
    auto sum{std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>{})};
    std::cout << "Sum: " << sum << '\n';

    // 1*1*3*7*9*11 = 2079
    auto product{
        std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>{})};
    std::cout << "Product: " << product << '\n';

    auto diff{std::accumulate(nums.begin(), nums.end(), 0, std::minus<int>{})};
    std::cout << "Difference(L-R): " << diff << '\n';
    // aha! it must be doing the operation like this:
    // 0-1-3-7-9-11 = 32

    // we can write diff better(and every std::accumulate):
    // We put the initial value as the first member of the array(as that should
    // really be the case), then proceeded to start operating on members past it
    diff = std::accumulate(std::next(nums.begin()), nums.end(), nums[0],
                           std::minus<int>{});
    // should return -29
    std::cout << "Difference(L->R): " << diff << '\n';

    return 0;
}