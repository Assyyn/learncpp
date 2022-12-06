#include <iostream>
#include <vector>
#include <utility>

using VectPairSI = std::vector<std::pair<std::string, int>>;    // easier to read and write this type now 
VectPairSI getVectPairSI()
{
    VectPairSI s;
    // fill s with required input
    return s;
}

int main()
{
    VectPairSI pairlist{getVectPairSI()};

    return 0;
}
// can be beneficial for documentation purposes where some things can be easily inferred with Type Aliases(use comments if and wherever possible instead)
// can be easier to maintain code
// all of the benefits come from the assumption that type aliases are properly used and cared for