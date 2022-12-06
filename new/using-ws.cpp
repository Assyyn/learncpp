#include <iostream>
#include <string>

int main()
{
    // an attempt at getting an int and a line of input. xFail

    std::cout << "pick 1 or 10: ";
    int choice{};
    std::cin >> choice;

    std::cout << "enter your name: ";
    std::string name;
    std::getline(std::cin, name);   // the newline from pressing the enter key after input of 'choice' is still in buffer,
                                    // so getline() assumes it as input. we fix this by using std::ws,
                                    // which tells getline() to ignore leading whitespace characters such as \n and \t
                                    // effectively preventing such unintended errors from happening in code.

    std::cout << "Hello " << name << " you entered " << choice << '\n';

    // a second attempt, this time using std::ws. xPass

    std::cout << "pick 1 or 10: ";
    int choice1{};
    std::cin >> choice1;

    std::cout << "enter your name: ";
    std::string name1;
    std::getline(std::cin >> std::ws, name1);

    std::cout << "Hello " << name1 << " you picked " << choice1 << '\n';

    return 0;
}