#include <iostream>
#include <string>

const int &getNextId() {
  static int s_x{0}; // note:variable non-const
  ++s_x;             // generate next id
  return s_x;        // and return a reference to it
}

int main() {
  const int &id1{getNextId()}; // id1 is a reference
  const int &id2{getNextId()}; // id2 is a reference

  std::cout << id1 << id2 << '\n';

  return 0;
}

// prints 22 because, s_x's value has now changed which is reflected in id1
//
// avoid returning references to non-const local static variables
