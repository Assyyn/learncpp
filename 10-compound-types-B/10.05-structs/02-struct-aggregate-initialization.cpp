#include <iostream>
#include <string>

struct Student
{
    std::string firstName;
    std::string lastName;
    int age{};
    int standard{};
};

int main()
{
    // copy-list initialization(not practical or optimal):
    Student brock = {"Brock", "Lesnar", 15, 12};
    // direct initialization using paranthesized list (C++20):
    Student killua("Killua", "Zoldyck", 12, 7);
    // list initialization using braced list (preferred):
    Student frank("Frank", "Zhang", 15, 12);

    // designated initializers
    Student harry{// C++20 onwards
                  .firstName{"Harry"},
                  .lastName{"Styles"},
                  .age{16},
                  .standard{12}};

    // missing initialization..
    Student himani{"Himani"}; // himani.lastName, age and standard have default
                              // value initialized(here, empty string and 0)
    Student john{};           // value initialize all members

    // const struct objects:
    const Student
        barry{}; // this is legal because we have value-initialized the object
    const Student hawa; // hmm.. why is this also possible?
    const Student winner{"Winner", "Kumal", 18, 12};

    return 0;
}