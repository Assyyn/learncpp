// Because lambdas are objects, they can be copied. In some cases, this can
// cause problems

#include <iostream>

int main()
{
    int i{0};

    // Create a new lambda named count
    auto count{[i] mutable { std::cout << ++i << '\n'; }};

    count(); // invoke count

    // this copies count in count's current state, which may not really be
    // intended
    auto otherCount{count}; // create a copy of count

    // maybe could fix by just referencing count?
    auto& secondCountCopy{count};

    // invoke both count and the copy
    count();
    secondCountCopy(); // this produces the desired result in this case
    otherCount();

    return 0;
}