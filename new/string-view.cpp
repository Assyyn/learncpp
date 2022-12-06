#include <iostream>
#include <string>
#include <string_view>

void printPrompt(std::string_view prompt)
{
    std::cout << prompt << '\n';
}

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{"Hello world!"}; // a std::string_view is useful when you need a read-only string as it does not copy the string
                                        // instead providing read-only access to the string
    printPrompt(s);

    constexpr std::string_view str{"this is a compile-time constant"};
    printPrompt(str);

    std::string name{"Yuuki"};
    printPrompt(name);                   // this implicit conversion is also legal

    std::string_view readOnlyName{name}; // implicitly convert std::string to std::string_view. initialization using this method is fine
    printPrompt(readOnlyName);

    std::string initFromStrView {readOnlyName}; // initializing a std::string from std::string_view
    printPrompt(initFromStrView);

    printString(static_cast<std::string> (readOnlyName)); // explicit type-conversion from std::string_view to std::string    

    return 0;
}