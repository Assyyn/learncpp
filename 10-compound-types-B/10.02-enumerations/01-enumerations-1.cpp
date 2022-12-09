// define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // Theses symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma is optional but recommended
};        // the enum definition must end with a semicolon

int main()
{
    // Define a few variables of enumerated type
    Color apple{red};
    Color grass{green};
    Color sky{blue};
    Color water{colorless}; // error: colorless is not an enumerator of Color
    Color socks{white};     // error: white is not an enumerator of Color

    return 0;
}

// Best practice:
// Name your enumerations starting with a Capital letter
// Name your enumerators starting with a lowercase letter