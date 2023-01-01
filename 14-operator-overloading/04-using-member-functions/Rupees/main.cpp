#include "Rupees.h"

#include <iostream>
#include <sstream>

int main()
{
    Rupees total{3500};

    Rupees momo{120};
    Rupees chiso{80};
    std::cout << "Momo+chiso costs " << (momo + chiso) << '\n';

    // test operator>> overload
    Rupees muesli{};
    std::istringstream dummyIn("Rs. 2000");
    dummyIn >> muesli;
    std::cout << muesli << '\n';

    // test *this.operator-(Rupees) overload
    total = total - (momo + chiso);
    std::cout << total << '\n';

    int miscCosts{130};
    // test operator-(int,Rupees) overload
    std::cout << "miscCosts-total=" << miscCosts - total << '\n';

    // test *this.operator-(int) overload
    total = total - miscCosts;
    std::cout << total << '\n';

    total += miscCosts;
    std::cout << total << '\n';

    return 0;
}