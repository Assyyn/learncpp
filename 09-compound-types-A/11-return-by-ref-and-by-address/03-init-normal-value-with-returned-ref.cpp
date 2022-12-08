#include <iostream>
#include <string>

const int &getNextId() {
  static int s_x{0};
  ++s_x;
  return s_x;
}

const std::string getProgramName() {
  const std::string programName{"Calculator"}; // local variable

  return programName;
}

int main() {
  const int id1{getNextId()}; // id1 receives a copy of the value returned
  const int id2{getNextId()}; // id2 receives a copy of the value returned

  std::cout << id1 << id2 << '\n';

  std::string name{getProgramName()}; // makes a copy of the dangling reference
  std::cout << "This program is named " << name << '\n'; // undefined behavior

  return 0;
}

// this defeats the purpose of returning a value by reference
// (to avoid making a copy of the return value)
