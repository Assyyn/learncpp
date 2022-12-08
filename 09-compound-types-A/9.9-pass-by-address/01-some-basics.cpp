#include <iostream>
#include <string>

// pass by address does not make a copy of the object being pointed to

void printByAddress(const std::string *ptr) {
  std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void changeValue(std::string *ptr) { *ptr = "Hello, !"; }

int main() {
  std::string str{"Hello, world!"};

  printByAddress(&str); // pass by address

  std::string *ptr{&str};
  printByAddress(ptr); // pass by address,
                       // through pointer that holds said address

  changeValue(ptr);    // modify str through ptr
  printByAddress(ptr); // prints 'Hello, !'

  return 0;
}
